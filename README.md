# SAXPY with SIMD in Assembly

This repository contains an implementation of the **SAXPY** operation (`y = alpha * x + y`) in assembly using SIMD (Single Instruction, Multiple Data) for efficient vector processing.

A Makefile is provided to simplify building and running the project. Additionally, a test program written in C is included to verify the correctness of the implementation and benchmark its performance.

## Mathematical Definition

The SAXPY (Single-Precision A·X Plus Y) operation is defined as:

$$
\mathbf{y} \gets \alpha \cdot \mathbf{x} + \mathbf{y}, \quad \mathbf{x}, \mathbf{y} \in \mathbb{R}^n, \ \alpha \in \mathbb{R}
$$

Where:
- $\mathbf{x}$ and $\mathbf{y}$ are vectors of dimension $n$,
- $\alpha$ is a scalar multiplier.

## Features
- **SAXPY Implementation**:
  - Optimised for performance using SIMD instructions.
  - Handles scalar remainders when vector size isn't divisible by the SIMD width (in this case 4).
- **Test Program**:
  - Generates random input arrays for testing.
  - Allows specifying vector size via command-line arguments.
  - Measures execution time for benchmarking.

## How to Build and Run

### Prerequisites
- GCC or another compiler supporting assembly.
- Make utility installed on your system.

### Build and Run
Example output:
```bash
> make
> ./main
Initial arrays (first 10 elements):
  x: -3.50 -1.80 -2.80 -0.50 -1.40 -3.20 -4.00 -3.30 0.10 -1.00 ...
  y: -1.20 4.40 3.80 0.70 -3.10 -5.00 -4.20 -5.00 1.20 -4.50 ...
  
After SAXPY (y = 2.50 * x + y):
  y: -9.95 -0.10 -3.20 -0.55 -6.60 -13.00 -14.20 -13.25 1.45 -7.00 ...
  
Execution time: 354 microseconds (0.354 milliseconds)
```
