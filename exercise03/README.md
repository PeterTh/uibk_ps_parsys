# Exercise 3

In this exercise, we study the auto-vectorization capabilities of various compilers,
and how different input code properties affect them.

## Programs to use

These three programs are supplied:
- `01_mmul_c_static.c`
- `02_mmul_c_dynamic.c`
- `03_mmul_cpp_dynamic.c`

For each of them, investigate vectorization with the `VALUE` type set to `double`, `int` and `float`, for a total of **9 source configurations**. 

## Compilers to use

- **gcc 7.2** with the options `-std=c++17 -O2 -mavx2`
- **clang 5.0** with the options `-std=c++17 -O2 -mavx2`
- **icc 17** with the options `-std=c++17 -O2 -march=core-avx2`
- **MSVC 19** with the options `/std:c++latest /O2 /arch:AVX2`

## Desired Result

From your investigation, create a table with the compilers as columns and the source/value type configurations as rows. In each cell, mark down the vectorization width (e.g. "4" if 4 double values are computed in one instruction) achieved by the associated compiler for the given configuration.

Note that we only care about the vectorization width of **the main multiplication loop**.

Also investigate whether a compiler performs loop unrolling.

**Suggestion**: use compiler explorer (https://godbolt.org/) to carry out this task. 
Note that you can easily navigate to the assembler code for a given input source line by right-clicking, but be aware that the source for one line might be distributed among interleaved instructions.

## General Note
*Every* member of your group should be ready to explain your methods and findings. All of you should also be able to answer in-depth question about the prblem studied.
