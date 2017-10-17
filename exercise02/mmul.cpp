#include <vector>
#include <cstdlib>

#include "chrono_timer.h"

#if !defined(NESTED_VECTOR) && !defined(CONTIGUOUS_WITH_MULTIPLICATION) && !defined(CONTIGUOUS_WITH_INDIRECTION)
#define NESTED_VECTOR
#endif

#if defined(NESTED_VECTOR)

struct Matrix : std::vector<std::vector<double>> {
	unsigned matSize;
	Matrix() : matSize(0) {}
	Matrix(unsigned n) : matSize(n) {
		resize(n);
		for(unsigned i = 0; i < n; ++i) {
			(*this)[i].resize(n);
		}
	}
	double& operator()(unsigned i, unsigned j) {
		return (*this)[i][j];
	}
	const double& operator()(unsigned i, unsigned j) const {
		return (*this)[i][j];
	}
};

#elif defined(CONTIGUOUS_WITH_MULTIPLICATION)

struct Matrix : std::vector<double> {
	unsigned matSize;
	Matrix() : matSize(0) {}
	Matrix(unsigned n) : matSize(n) {
		resize(n*n);
	}
	double& operator()(unsigned i, unsigned j) {
		return (*this)[i*matSize + j];
	}
	const double& operator()(unsigned i, unsigned j) const {
		return (*this)[i*matSize + j];
	}
};

#elif defined(CONTIGUOUS_WITH_INDIRECTION)

struct Matrix : std::vector<double> {
	unsigned matSize;
	std::vector<double*> indirection;
	Matrix() : matSize(0) {}
	Matrix(unsigned n) : matSize(n) {
		resize(n*n);
		indirection.resize(n);
		for(unsigned i = 0; i < n; ++i) {
			indirection[i] = &(*this)[i*n];
		}
	}
	double& operator()(unsigned i, unsigned j) {
		return indirection[i][j];
	}
	const double& operator()(unsigned i, unsigned j) const {
		return indirection[i][j];
	}
};

#endif

// initializes a matrix of size n x n
template<typename F>
Matrix init(unsigned n, F initFun) {
	Matrix res(n);
	for(unsigned i = 0; i < n; i++) {
		for(unsigned j = 0; j < n; j++) {
			res(i,j) = initFun(i, j);
		}
	}
	return res;
}

// computes the product of two matrices
Matrix operator*(const Matrix& a, const Matrix& b) {
	unsigned n = a.matSize;
	Matrix c = init(n, [](unsigned, unsigned) { return 0; });
	for(unsigned i = 0; i < n; ++i) {
		for(unsigned k = 0; k < n; ++k) {
			for(unsigned j = 0; j < n; ++j) {
				c(i,j) += a(i,k) * b(k,j);
			}
		}
	}
	return c;
}

int main(int argc, char** argv) {

	if(argc != 2) return EXIT_FAILURE;
	unsigned n = atoi(argv[1]);
	if(n == 0) return EXIT_FAILURE;
	
	// create two matrices
	auto a = init(n, [](unsigned i, unsigned j) { return (i==0) && (j==0) ? 42.0 : 0.0; });
	auto b = init(n, [](unsigned i, unsigned j) { return (i == j) ? 1.0 : 0.0; });

	Matrix c;
	// compute the product
	{
		ChronoTimer t("Multiplication");
		c = a * b;
	}

	// check that the result is correct
	auto ret = (c == a) ? EXIT_SUCCESS : EXIT_FAILURE;
	std::cout << "Ret: " << ret << std::endl;
	return ret;
}
