# Assignment-7-oussema-kassebi

Link of the original code to be optimized:
https://github.com/notdanieldiaz/Matrix-Multiplication

+ Optimization task:
This project demonstrates performance gains in matrix multiplication using modern C++ features. The task highlights the replacement of a  naive implementation with an optimized version using parallel algorithms and cache-friendly techniques.

Remarkable significant improvements include:
 1 - Dynamic Memory Allocation:
 Using std::vector for dynamic memory allocation simplifies memory management and ensures exception safety.
 2 - Parallel Processing: #pragma omp parallel for collapse(2) which enables parallel processing of:
 nested loops, significantly reducing computation time by leveraging multiple CPU cores.
 3 - Efficient Loop Structures:
 The loops are structured to maximize cache performance and minimize memory access latency.
 4 - Improved code structure and size:
 Reducing code lines to roughly 60% and so in code file size.
