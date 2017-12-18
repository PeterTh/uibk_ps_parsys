# Exercise 10

In this exercise, we port more programs to distributed memory, and also repeat the stencil benchmarks with smaller epsilon values.


### 10.1 - Distributed Memory Dense Matrix-Matrix Multiplication

Implement a distributed memory MPI version of dense matrix-matrix multiplication (as discussed and implemented for shared memory in the first few exercises).
Consider the most advantageous data distribution pattern, and how to efficiently gather the results.

How do these considerations change when you want to perform a sequence of multiple multiplications in which you re-use your output matrix?

### 10.2 Distributed Memory N-Queens Solver

Create a distributed memory MPI version of your N-Queens solver (see exercise 4 and 5). 

Benchmark it against the shared memory OpenMP version on a single node, using 1, 2, 4, and 8 processes / threads each.

How would an optimal parallelization pattern of this this program look like for our small cluster? And how would it differ if you had a supercomputer with more than 10000 nodes available?

### 10.3 Benchmarking Stencil, again

Re-run the benchmarks from Exercise 9, but this time use an epsilon value of **1.0** for both grid sizes.

Investigate the impact of the optimizations implemented in exercise 9.


## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 5 minutes at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
