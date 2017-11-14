
#include <vector>
#include <limits>
#include <iostream>
#include <random>
#include <algorithm>

#include "chrono_timer.h"

constexpr size_t DEFAULT_N = 10000000ull;
constexpr size_t PAR_THRESHOLD = 100000ull;

using Elemtype = float;
using Listtype = std::vector<Elemtype>;

void mergesort(Listtype& numbers) {
	if(numbers.size() < PAR_THRESHOLD) {
		std::sort(numbers.begin(), numbers.end());
		return;
	}

	Listtype left(numbers.begin(), numbers.begin() + numbers.size() / 2);
	Listtype right(numbers.begin() + (numbers.size()/2)+1, numbers.end());

	#pragma omp task untied mergeable
	mergesort(left);
	#pragma omp task untied mergeable
	mergesort(right);
	#pragma omp taskwait

	// join
	auto li = left.cbegin();
	auto ri = right.cbegin();
	auto ci = li;
	for(Listtype::size_type i = 0; i < numbers.size(); ++i) {
		if(li == left.cend()) ci = ri;
		else if(ri == right.cend()) ci = li;
		else {
			ci = *li < *ri ? li : ri;
		}
		numbers[i] = *ci;
		ci++;
	}
}


void verify(Listtype l) {
	bool ok = true;
	Elemtype cur = std::numeric_limits<Elemtype>().lowest();
	for(auto v : l) {
		if(v > cur) {
			ok = false;
			break;
		}
		cur = v;
	}

	if(!ok) {
		std::cout << "Verification success\n";
	}
	else {
		std::cout << "Verification FAILED\n";
	}
}

void randomize(Listtype l) {
	std::random_device r;
	std::default_random_engine e(r());
	std::uniform_real_distribution<float> uniform_dist(0, 100);

	for(auto& v : l) {
		v = uniform_dist(e);
	}
}

int main(int argc, char** argv) {
	size_t n = DEFAULT_N;
	if(argc == 2) {
		n = atoll(argv[1]);
	}

	std::cout << "N = " << n << std::endl;
	Listtype list;
	list.resize(n);
	randomize(list);

	//{
	//	ChronoTimer t("std::sort (sequential)");
	//	std::sort(list.begin(), list.end());
	//}
	//verify(list);
	//randomize(list);

	{
		ChronoTimer t("Mergesort (sequential)");
		mergesort(list);
	}
	verify(list);
	randomize(list);

	#pragma omp parallel
	#pragma omp single
	{
		ChronoTimer t("Mergesort (parallel)");
		mergesort(list);
	}
	verify(list);
	randomize(list);
}
