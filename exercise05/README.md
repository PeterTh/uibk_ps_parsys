# Exercise 5

The goal of this exercise is to optimize the algorithms implemented last week
(N-Queens, Merge Sort, and a Monte Carlo estimator for pi), and perform sequential and parallel optimizations as well as in-depth benchmarks on the LCC2 cluster.

## LCC2
All of you should have received accounts for this cluster, and changed the starting password.
*If you have not yet done the latter, please do so as soon as possible.*

You can find more information about this system here: https://www.uibk.ac.at/zid/systeme/hpc-systeme/lcc2/

In particular, the following tutorial explains how to use the **SGE** system to submit jobs:
https://www.uibk.ac.at/zid/systeme/hpc-systeme/common/tutorials/sge-howto.html

**Please do not run any benchmarks or heavy CPU loads on the login node.**
If you want to do some interactive experimentation, use an *interactive job* as outlined in the tutorial.
**Also ensure that your programs don't meaninglessly occupy cluster resources**.

## Optimization Rules
You are free to perform any kind of optimization, both parallel and sequential, as long as it follows these rules:
- For N-queens, use a backtracking algorithm, and do not modify the underlying algorithm for mergesort and the pi estimator
    * In particular, the parallelization of the algorithm needs to follow the same basic algorithmic structure; Leaf-level algorithmic optimizations are valid. 
- Only C++ code is allowed.
- Manual parallelization should be performed with OpenMP only.

You are also free to choose any compiler (and compiler options) available on the cluster.

## Benchmarking
Please run these benchmarks once for your original algorithm, and once for your final optimized version.

Test the following configurations:
- The optimized sequential version
- The parallel version with 1, 2, 4 and 8 threads
- At least 3 problem sizes for each benchmark
    - For N-queens, include at least the sizes 8, 10 and 12
    - For Merge sort, include 100 000 000 int32_t as one of the cases
    - For the pi estimation, include 1 000 000 samples as one option

Document your results, and the improvement achieved by your optimizations and parallelizations.

## Winners
For each algorithm, up to two winning teams will be chosen, one for the fastest sequential version and one for the fastest parallel version.
The winners receive a bonus point.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
