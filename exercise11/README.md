# Exercise 11

In this exercise, the goal is to apply what we learned to a **"real-world"** code.

The file `real.tar` contains a realistic example of a numerical algorithm. The scenario we imagine for this exercise is that this is the code you received from somehwere (without further explanation), and you are tasked with making it faster and parallelizing it effectively.

### 10.1 - Performance Investigation 

Get familiar with the code, and apply the various profiling techniques we discussed to determine its most performance-critical areas (e.g. functional profiling), as well as which types of hardware load they primarily cause (e.g. CPU counters).

### 10.2 Optimization & Parallelization

Optimize the crucial code paths, investigate the relevant loops you find, and determine if and how they can be parallelized. Perform the parallelization using OpenMP.

### 10.3 Performance Benchmarking

Benchmark the performance of the original sequential program, as well as your optimized and parallelized version with 1, 2, 4 and 8 threads on a single node of the LCC2 cluster.

## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 5 minutes at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
