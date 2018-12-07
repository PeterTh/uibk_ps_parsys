# Exercise 8

This exercise consists of two independent tasks:
1. Create a distributed memory parallel version (using MPI) of the Monte Carlo estimator for pi that was previously implemented for shared memory.
2. Create an MPI version of the 1D, 2D and 3D stencil algorithm.

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
