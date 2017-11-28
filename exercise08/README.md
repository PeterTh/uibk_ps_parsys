# Exercise 8

This exercise consist of three independent tasks:
1. Measure the performance of your shared memory 2D stencil algorithm on a fixed baseline, for comparison to the other groups.
2. Create a distributed memory parallel version (using MPI) of the Monte Carlo estimator for pi that was previously implemented for shared memory.
3. Create an MPI version of the 1D, 2D and 3D stencil algorithm.

## Shared memory stencil benchmarking

Benchmark using this setup:
- 2D grid of 512x512 cells
- 5 point heat stencil
- Iterate until Epsilon (as the sum of all changes across the grid) is less than 20.
- North/East/South/West boundaries fixed at 1.0, 0.5, 0.0 and -0.5 respectively

With 1, 2, 4 and 8 threads on a single node of the cluster.

## Monte Carlo pi estimator and stencil MPI versions

For this week, no large-scale benchmarking is required yet. 
The goal is to get a correct distributed memory version of the programs which runs at least somewhat faster on two nodes than a single node.

Regarding the stencil data distribution, remember our discussion within the lab concerning ghost cell exchange.

*Note that you can develop and debug MPI programs by running multiple processes on a single system.*

## Unit Testing
Your programs and their individual components should be unit tested. 

## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 5 minutes at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
