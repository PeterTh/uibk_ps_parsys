# Exercise 12 (Final Exercise)

In this final exercise we return to the **2D stencil code**.
In HPC, one available implementation pattern is *hybrid parallelization*. The idea is, for a cluster of `N` nodes with `C` cores each, to create an MPI parallelization that distributes the computation across `N` processes (one per node), each of which uses `C` parallel threads.

[Consider this reference for more information](https://www.researchgate.net/publication/221392799_Hybrid_MPIOpenMP_parallel_programming_on_clusters_of_multi-core_SMP_nodes).

### 12.1 Setup & Design

Study the available options for launching MPI programs in SGE, and decide which to use for this purpose. Test that your proposed setup actually achieves the goal (of having 8 hardware threads available within a single process per node).

Also consider how you want to distribute the data, and how you will implement communication in your threaded per-node programs.

### 12.2 Implementation

Implement a hybrid OpenMP / MPI version of the 2D stencil computation.

### 12.3 Performance Evaluation

Compare the performance of your hybrid solution to the MPI-only version on 2 and 4 cluster nodes using our established benchmark parameters.

## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 5 minutes at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
