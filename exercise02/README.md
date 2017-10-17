# Exercise 2 - Mulling over mmul

This exercise has 2 major parts. 
- In part 1, we investigate some interesting behaviour uncovered in exercise 1 using CPU counters.
- In part 2, we look at how input data can influence the way we optimize and parallelize algorithms.

### Part 1

The code file `mmul.cpp` contains an updated version of our simple sequential matrix multiplication example.
It features 3 subtly different implementations of the matrix data structure. They are labeled `NESTED_VECTOR`, `CONTIGUOUS_WITH_MULTIPLICATION`, and `CONTIGUOUS_WITH_INDIRECTION`.
*Note:* You can easily select which version will be used by supplying a `-D` parameter to your compiler call, e.g. `-DCONTIGUOUS_WITH_MULTIPLICATION`.

Complete the following steps:
 - Study the 3 versions. What is the difference between them, and how would expect this to manifest in terms of performance?
 - Use the [**perf** tool](http://www.brendangregg.com/perf.html) (or an equivalent if you are using a non-Linux system) to measure CPU counters for these benchmark versions. Study the set of available counters and try to find ones which you expect to be relevant for this task. *Note: for the systems in the university rooms, you should be able to use `perf` located in `/scratch/c703/c703432`*
 - Add the measurement of CPU counters and all 3 configuration versions to your benchmark regimen and document all findings. You should also update the way you perform benchmarks according to the points discussed (e.g. multiple runs, median calculation, etc.).

### Part 2

Complete the following steps:
- Assume that the right-hand-side matrix in our matrix multiplication example is always an **upper triangular matrix**. How would you use this knowledge to sequentially optimize the code? Apply your optimizations and document their impact using your benchmarking regimen.
- What impact does this optimization have on the effectiveness of a simple OpenMP parallelization? How would you optimize your parallelization strategy for this case? Implement your ideas and document their performance impact.


**Note:**
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about your solution.



