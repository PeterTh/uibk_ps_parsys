# Exercise 9

In this exercise, we are optimizing and benchmarking our stencil implementation. We are only focusing on the 2D stencil for now.


## Optimizations

We want to investigate several different optimizations:
1. Use 2D subdivision of the grid instead of 1D subdivision.
2. Perform all send and receive operations without blocking.
3. Interleave the inner computation of each tile of the stencil with communicating the ghost cells.
4. [Bonus] One more optimization (of the parallel execution, not the sequential program) that you come up with on your own.

For each of these optimizations, track your progress by using the benchmarking regimen outlined below.

Ascii art for the third optimization (showing a single tile and its surroundings):

```
     ...                     ...
      |                       |
      |    2                  |
...-------------------------------...
      |    1          4       |
      |  |-----------------|  |
    2 |1 | 3. compute      |1 |2
      |  |    inner        |  |
      |4 |-----------------|4 |
      |    1          4       |
...-------------------------------...
      |    2                  |
      |                       |
     ...                     ...
```

In step 1, the outermost cells (the surrounding tiles' ghost cells) are sent out. 
Then, in step 2, the own ghost cells are received *asynchronously*. Step 3, computing 
the inner cells, is started immediately. Then, we block until the ghost cells have been received
(which likely already happened). In step 4, we calcualte the new ghost cells.


## Benchmarking

Benchmark using this setup:
- 2 different sizes : **512x512** and **768x768**
- 5 point heat stencil
- **`double`** datatype
- Iterate until Epsilon (as the sum of all changes across the grid) is less than **10.0** for the 512² gird, and **100.0** for the 768² grid
- North/East/South/West boundaries fixed at **1.0, 0.5, 0.0 and -0.5** respectively
- All initial values should be set to **0.0**
- Use the **-O3 and -march=native** compiler flags (not -Ofast)

*Use 1, 2, 4 and 8 processes on a single node of the cluster,
as well as 2, 4 and 8 nodes across the cluster (using 16, 32 and 64 cores/processes respectively).*

**Create a chart which shows the perforamnce scaling across all 7 increasing core counts.**

## Unit Testing
Your programs and their individual components should be unit tested. 

## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 5 minutes at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
