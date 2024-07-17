# Assignment-7-oussema-kassebi

Link of the original code to be optimized:
https://github.com/PiotrMydlowski/Matrix-Basic/blob/master/main.cpp

Main code task: 

Write a program which performs addition, subtraction, multiplication of matrices.
The dimensions of both the matrices would be specified by the user (dynamic memory allocation required).
Use of structure or a class to define the matrix would be a good idea.


+ Optimization task:
This project demonstrates performance gains in matrix multiplication using modern C++ features. The task highlights the replacement of a  naive implementation with an optimized version using dynamic memory allocation, parallel algorithms and cache-friendly techniques.

Remarkable significant improvements include:

 1 - Dynamic Memory Allocation:
 
 Using std::vector for dynamic memory allocation simplifies memory management and ensures exception safety.
     
 2 - Parallel Processing:
 
#pragma omp parallel for collapse(2) which enables parallel processing of nested loops, significantly reducing computation time by leveraging multiple CPU cores.
 
 3 - Efficient Loop Structures:
 
 The loops are structured to maximize cache performance and minimize memory access latency.
     
 4 - Improved code structure and size:
 
 Reducing code lines to roughly 60% and so in file size.


 Compilation command:
 
 g++ -fopenmp -o assignment7 Assignment7.cpp
 
 Execution command:
 
 ./assignment7
