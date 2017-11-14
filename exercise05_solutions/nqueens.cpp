#include <cstdlib>
#include <cassert>

#include <vector>
#include <bitset>
#include <array>
#include <chrono>
#include <iostream>

#include "chrono_timer.h"

constexpr int DEFAULT_N = 14;
constexpr int MAX_N = 32;

constexpr int MAX_VERIFY = 16;
constexpr long long CHECK_RESULTS[MAX_VERIFY] = { 0ll, 0ll, 0ll, 0ll, 2ll, 10ll, 4ll, 40ll, 92ll, 352ll, 724ll, 2680ll, 14200ll, 73712ll, 365596ll, 2279184ll };

struct Queen {
	char x = -1;
	char y = -1;
	Queen() {}
	Queen(char x, char y) : x(x), y(y) {}
};

//#define SIMPLE_VECTOR_IMPL
//#define SIMPLE_ARRAY_IMPL
//#define ARR_WITH_LINES
//#define YPOS_OPT
//#define DIAG_DATA
//#define SEQ_OPT
#define TEMPLATE_MAGIC

#ifdef SIMPLE_VECTOR_IMPL

using History = std::vector<Queen>;

inline bool is_valid_placement(int x, int y, const History& history) {
	for(auto q : history) {
		if(y == q.y) return false; // same row
		if(x - q.x == abs(q.y - y)) return false; // same diagonal
	}
	return true;
}

long long nqueens_seq_impl(int n, int cur_x, const History& history) {
	if(cur_x == n) return 1;
	long long ret = 0;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			auto copy = history;
			copy.emplace_back(cur_x, i);
			ret += nqueens_seq_impl(n, cur_x + 1, copy);
		}
	}
	return ret;
}

#elif defined(SIMPLE_ARRAY_IMPL)

struct History {
	int length = 0;
	std::array<Queen, MAX_N> arr;

	void insert(char x, char y) {
		arr[length].x = x;
		arr[length].y = y;
		length++;
	}

	const Queen* begin() const { return &arr[0]; }
	const Queen* end() const { return &arr[length]; }
};

inline bool is_valid_placement(int x, int y, const History& history) {
	for(const auto& q : history) {
		if(y == q.y) return false; // same row
		if(x - q.x == abs(q.y - y)) return false; // same diagonal
	}
	return true;
}

long long nqueens_seq_impl(int n, int cur_x, const History& history) {
	if(cur_x == n) return 1;
	long long ret = 0;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			auto copy = history;
			copy.insert(cur_x, i);
			ret += nqueens_seq_impl(n, cur_x + 1, copy);
		}
	}
	return ret;
}

#elif defined(ARR_WITH_LINES)

struct History {
	int length = 0;
	std::array<Queen, MAX_N> arr;
	std::array<bool, MAX_N> lines{ false };

	void insert(char x, char y) {
		arr[length].x = x;
		arr[length].y = y;
		lines[y] = true;
		length++;
	}

	const Queen* begin() const { return &arr[0]; }
	const Queen* end() const { return &arr[length]; }
};

inline bool is_valid_placement(int x, int y, const History& history) {
	if(history.lines[y]) return false; // same row
	for(const auto& q : history) {
		if(x - q.x == abs(q.y - y)) return false; // same diagonal
	}
	return true;
}

long long nqueens_seq_impl(int n, int cur_x, const History& history) {
	if(cur_x == n) return 1;
	long long ret = 0;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			auto copy = history;
			copy.insert(cur_x, i);
			ret += nqueens_seq_impl(n, cur_x + 1, copy);
		}
	}
	return ret;
}

#elif defined(YPOS_OPT)

struct History {
	std::array<char, MAX_N> ypos;
	std::array<bool, MAX_N> lines{ false };

	void insert(char x, char y) {
		ypos[x] = y;
		lines[y] = true;
	}
};

inline bool is_valid_placement(int x, int y, const History& history) {
	if(history.lines[y]) return false; // same row
	for(int qx = 0; qx < x; ++qx) {
		if(x - qx == abs(history.ypos[qx] - y)) return false; // same diagonal
	}
	return true;
}

long long nqueens_seq_impl(int n, int cur_x, const History& history) {
	if(cur_x == n) return 1;
	long long ret = 0;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			auto copy = history;
			copy.insert(cur_x, i);
			ret += nqueens_seq_impl(n, cur_x + 1, copy);
		}
	}
	return ret;
}

#elif defined(DIAG_DATA)

struct History {
	std::array<bool, MAX_N> lines{ false };
	std::array<bool, MAX_N * 2> diags{ false };
	std::array<bool, MAX_N * 2> rdiags{ false };

	void insert(char x, char y) {
		lines[y] = true;
		diags[y - x + MAX_N] = true;
		rdiags[y + x] = true;
	}
};

inline bool is_valid_placement(int x, int y, const History& history) {
	if(history.lines[y]) return false; // same row
	if(history.diags[y - x + MAX_N]) return false; // same diagonal
	if(history.rdiags[y + x]) return false; // same reverse diagonal
	return true;
}

long long nqueens_seq_impl(const int n, const int cur_x, const History& history) {
	if(cur_x == n) return 1ll;
	long long ret = 0;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			auto copy = history;
			copy.insert(cur_x, i);
			ret += nqueens_seq_impl(n, cur_x + 1, copy);
		}
	}
	return ret;
}

#elif defined(SEQ_OPT)

struct History {
	std::array<bool, MAX_N> lines{ { false } };
	std::array<bool, MAX_N * 2> diags{ { false } };
	std::array<bool, MAX_N * 2> rdiags{ { false } };

	void set(char x, char y, bool val) {
		lines[y] = val;
		diags[y - x + MAX_N] = val;
		rdiags[y + x] = val;
	}
};

inline bool is_valid_placement(const int x, const int y, const History& history) {
	if(history.lines[y]) return false; // same row
	if(history.diags[y - x + MAX_N]) return false; // same diagonal
	if(history.rdiags[y + x]) return false; // same reverse diagonal
	return true;
}

long long nqueens_seq_impl(const int n, const int cur_x, History& history) {
	if(cur_x == n) return 1ll;
	long long ret = 0ll;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			history.set(cur_x, i, true);
			ret += nqueens_seq_impl(n, cur_x + 1, history);
			history.set(cur_x, i, false);
		}
	}
	return ret;
}

#elif defined(TEMPLATE_MAGIC)

struct History {
	std::array<bool, MAX_N> lines{ { false } };
	std::array<bool, MAX_N * 2> diags{ { false } };
	std::array<bool, MAX_N * 2> rdiags{ { false } };

	void set(char x, char y, bool val) {
		lines[y] = val;
		diags[y - x + MAX_N] = val;
		rdiags[y + x] = val;
	}
};

inline bool is_valid_placement(const int x, const int y, const History& history) {
	if(history.lines[y]) return false; // same row
	if(history.diags[y - x + MAX_N]) return false; // same diagonal
	if(history.rdiags[y + x]) return false; // same reverse diagonal
	return true;
}

constexpr int TEMPLATE_CUTOFF = 12;

template<int rem>
long long nqueens_seq_temp(const int n, History& history) {
	long long ret = 0ll;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(n - rem, i, history)) {
			history.set(n - rem, i, true);
			ret += nqueens_seq_temp<rem - 1>(n, history);
			history.set(n - rem, i, false);
		}
	}
	return ret;
}

template<>
long long nqueens_seq_temp<0>(const int n, History& history) {
	return 1ll;
}

long long nqueens_seq_impl(const int n, const int cur_x, History& history) {
	if(cur_x == n) return 1ll;
	long long ret = 0ll;
	for(int i = 0; i < n; ++i) {
		if(is_valid_placement(cur_x, i, history)) {
			history.set(cur_x, i, true);
			if(n - cur_x == TEMPLATE_CUTOFF) {
				ret += nqueens_seq_temp<TEMPLATE_CUTOFF - 1>(n, history);
			}
			else {
				ret += nqueens_seq_impl(n, cur_x + 1, history);
			}
			history.set(cur_x, i, false);
		}
	}
	return ret;
}

#endif

long long nqueens_par(const int n) {
	long long ret = 0ll;
#pragma omp parallel for schedule(dynamic) reduction(+:ret)
	for(int i = 0; i < n; ++i) {
		History history;
		history.set(0, i, true);
		ret += nqueens_seq_impl(n, 1, history);
	}
	return ret;
}


long long nqueens_seq(int n) {
	History history;
	return nqueens_seq_impl(n, 0, history);
}

void verify(long long result, int n) {
	std::cout << "Result: " << result << " possible placements\n";
	if(n < MAX_VERIFY) {
		if(CHECK_RESULTS[n] == result) {
			std::cout << "Verification success\n";
		}
		else {
			std::cout << "Verification FAILED\n";
		}
	}
}

int main(int argc, char** argv) {
	int n = DEFAULT_N;
	if(argc == 2) {
		n = atoi(argv[1]);
	}

	std::cout << "N = " << n << std::endl;

	long long result = 0;
	{
		ChronoTimer t("NQueens calculation (sequential)");
		result = nqueens_seq(n);
	}
	verify(result, n);

	{
		ChronoTimer t("NQueens calculation (parallel)");
		result = nqueens_par(n);
	}
	verify(result, n);
}
