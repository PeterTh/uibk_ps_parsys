# Exercise 6

The goal of this exercise is to implement, optimize, parallelize and benchmark an algorithm for performing insertions in an **AVL tree**. 
You do not need to worry about other operations, such as deletions.

The program should be structured as follows:
1. Generate N (command line parameter) random `unsigned int` values between `0` and `N/8`.
2. Insert these values into the AVL tree structure. 
Note that it is not permissible to sort the values before doing so, and that you need to maintain the AVL tree conditions throughout.
3. Check that the AVL tree is correctly structured and contains all the values (and no duplicates).

**Only the time for step 2 should be measured.** This is also the step which should be parallelized. Consider the parallelization strategy and how to effectively synchronize operations on the shared tree data structure.

## About Duplicate Values
Some questions came up about duplicate values. Yes, due to the design of this benchmark duplicate values will occur in your N numbers. This is fully intentional. The AVL tree should only contain one isntance of each number, but the idea is that for the benchmarked step (2) you need to call the equivalent of `tree->insert(x)` for all N numbers, and the insert procedure itself should figure out if a number is a duplicate and omit it.

## LCC2
All benchmarks should be performed on the LCC2 cluster. *Please make sure that your benchmarking runs do not take more than 1 minute at most.* Shorter runs are preferable.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the problem studied.
