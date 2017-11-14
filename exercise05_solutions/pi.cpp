
#include <random>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cinttypes>
#include <functional>

#include <omp.h>

#include "chrono_timer.h"
#include "sfmt/SFMT.h"

constexpr double PI = 3.14159265358979323846;

constexpr size_t DEFAULT_N = 100000000ull;

size_t monte_carlo_pi_hits(size_t n) {
	std::default_random_engine e(omp_get_thread_num()*31337);
	std::uniform_real_distribution<float> uniform_dist(0, 1);

	size_t hits = 0;
	for(size_t i = 0; i < n; ++i) {
		float x = uniform_dist(e);
		float y = uniform_dist(e);
		if(x*x + y*y <= 1.0f) hits++;
	}
	return hits;
}

size_t monte_carlo_pi_hits_sfmt(size_t n) {
	sfmt_t state;
	sfmt_init_gen_rand(&state, omp_get_thread_num() * 31337);
	size_t hits = 0;
	for(size_t i = 0; i < n; ++i) {
		double x = sfmt_genrand_real1(&state);
		double y = sfmt_genrand_real1(&state);
		if(x*x + y*y <= 1.0f) hits++;
	}
	return hits;
}

double pi_from_hits(size_t hits, size_t n) {
	return ((double)hits * 4.0) / (double)n;
}


int main(int argc, char** argv) {
	size_t n = DEFAULT_N;
	if(argc == 2) {
		n = atoll(argv[1]);
	}
	std::cout.precision(10);

	auto output = [](double pi) {
		std::cout << "Approximation: " << pi << std::endl;
		std::cout << "Error: " << std::fixed << fabs(pi - PI) * 100 << " %" << std::endl;
	};

	auto bench_sequential = [&](const char* name, std::function<size_t(size_t)> hit_fun) {
		ChronoTimer t(name);
		return pi_from_hits(hit_fun(n), n);
	};

	auto bench_parallel = [&](const char* name, std::function<size_t(size_t)> hit_fun) {
		ChronoTimer t(name);
		size_t hits = 0;
		#pragma omp parallel reduction(+:hits)
		{
			hits = hit_fun(n / omp_get_num_threads());
		}
		return pi_from_hits(hits, n);
	};

	output(bench_sequential("Approximating Pi [stdlib] (sequential)", monte_carlo_pi_hits));
	output(bench_parallel("Approximating Pi [stdlib] (parallel)", monte_carlo_pi_hits));

	output(bench_sequential("Approximating Pi [SFMT] (sequential)", monte_carlo_pi_hits_sfmt));
	output(bench_parallel("Approximating Pi [SFMT] (parallel)", monte_carlo_pi_hits_sfmt));

}
