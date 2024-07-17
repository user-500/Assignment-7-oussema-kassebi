// The following is the optimized code

#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <ctime>

// Matrix class definition
class Matrix {
public:
    int width, height;
    std::vector<std::vector<float>> data;
    // Constructor with dynamic allocation
    Matrix(int w, int h) : width(w), height(h), data(h, std::vector<float>(w, 0)) {}
    // Function to fill the matrix with random values
    void randomize(int limit) {
        #pragma omp parallel for collapse(2)
        for (int i = 0; i < height; i++) { 
            for (int j = 0; j < width; j++) {data[i][j] = rand() % limit; } 
        } 
    }

    // Function to print the matrix
    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row) { std::cout << val << "\t"; }
        std::cout << "\n"; } 
    std::cout << "\n";
    }
};

// Function to add or subtract two matrices
Matrix matrixAdd(const Matrix& A, const Matrix& B, bool subtract = false) {
    if (A.width != B.width || A.height != B.height) {
        throw std::invalid_argument("Dimension mismatch for addition/subtraction"); }
    Matrix result(A.width, A.height);
    float scalar = subtract ? -1 : 1;
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A.height; i++) {
        for (int j = 0; j < A.width; j++) { result.data[i][j] = A.data[i][j] + B.data[i][j] * scalar; }
    } return result;
}

// Function to multiply two matrices
Matrix matrixMultiply(const Matrix& A, const Matrix& B) {
    if (A.width != B.height)
        throw std::invalid_argument("Dimension mismatch for multiplication");
    Matrix result(B.width, A.height);
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < A.height; i++) {
        for (int j = 0; j < B.width; j++) {
            for (int k = 0; k < A.width; k++) {result.data[i][j] += A.data[i][k] * B.data[k][j]; }
        }
    }
    return result;
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int w, h;
    // Initialize and randomize first matrix
    std::cout << "Width and height of first matrix: "; std::cin >> w >> h; Matrix A(w, h); A.randomize(5); 
    // Initialize and randomize second matrix
    std::cout << "Width and height of second matrix: "; std::cin >> w >> h; Matrix B(w, h); B.randomize(5); 
    std::cout << "Matrix A:\n"; A.print();
    std::cout << "Matrix B:\n"; B.print();

    // Perform and print addition and subtraction in a single try-catch block
    try {
        Matrix C = matrixAdd(A, B); std::cout << "Matrix A + B:\n"; C.print();
        // Use subtraction mode
        Matrix D = matrixAdd(A, B, true); std::cout << "Matrix A - B:\n"; D.print(); }
    catch (const std::exception& e) { std::cout << e.what() << std::endl;}

    // Perform and print multiplication
    try { Matrix E = matrixMultiply(A, B); std::cout << "Matrix A * B:\n"; E.print(); }
    catch (const std::exception& e) { std::cout << e.what() << std::endl; }

    return 0;
}
