# Exercise 1

This is an introductory exercise designed to show the ideas and tools involved with **performance-oriented programming**.
We start with one of the most common and basic performance-oriented programming examples:
**Dense matrix-matrix multiply**.

The code for a very basic C++ matrix multiplication example is available in `mmul.cpp`. 
(Compile e.g. with `g++ mmul.cpp -o mmul -std=c++11 -Wall`)

Complete the following steps:

 - Study the usage of the **gprof** tool. Apply it to the matrix multiplication example and study the report. (Also commit it to your git repo)
   Try this with both a version compiled using `-O0` and one with `-O3` and observe the differences.
 - Establish a **benchmarking regimen** for this matrix multiply example. This should include a set of well-defined *problem sizes* (at least 5), a set of *hardware platforms*, and a set of *metrics* (e.g. wall time, cpu time, ...) that you are measuring. Think about issues such as statistical variation and external load, and how to minimize their impact on your results.
 - Try out at least **two methods of performing sequential optimization** on this matrix multiplication program. For each of them, *apply your benchmarking regimen and **document** your findings*. Also try to explain the results you observe.
 - Study **OpenMP `parallel` and `for`** and attempt to parallelize the matrix multiplication program using OpenMP. Once again, *apply your benchmarking regimen and **document** your findings*.

**Note:**
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about your solution.



