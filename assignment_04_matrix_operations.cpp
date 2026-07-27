// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// The funtion to input a matrix from the user
void inputMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// The function to display a matrix 
void displayMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// The function to transpose a matrix
void transposeMatrix(int matrix[10][10], int transposed[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// The function to add two matrices
void addMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

// The function to multiply two matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int result[10][10], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10]; 
    int transposed[10][10];
    int rows, cols;
    int matrixA[10][10], matrixB[10][10], sum[10][10];
    // Part A: Transpose a Matrix
    cout << "PART A : MATRIX TRANSPOSE" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    inputMatrix(matrix, rows, cols);
    transposeMatrix(matrix, transposed, rows, cols);
    cout << "Original Matrix:" << endl;
    displayMatrix(matrix, rows, cols);
    cout << "Transposed Matrix:" << endl;
    displayMatrix(transposed, cols, rows);

    // Part B: Add Two Matrices
    cout << "PART B : MATRIX ADDITION" << endl;
    cout << "Enter elements for the first matrix:" << endl;
    inputMatrix(matrixA, rows, cols);
    cout << "Enter elements for the second matrix:" << endl;
    inputMatrix(matrixB, rows, cols);
    addMatrices(matrixA, matrixB, sum, rows, cols);
    cout << "Sum of the two matrices:" << endl;
    displayMatrix(sum, rows, cols);

    // Part C: Multiply Two Matrices
    cout <<"PART C : MATRIX MULTIPLICATION";
    int rowsA, colsA, rowsB, colsB;
    int matrixC[10][10];
    int matrixD[10][10];
    int product[10][10];
    cout << "\nEnter number of rows for matrix A: ";
    cin >> rowsA;
    cout << "Enter number of columns for matrix A: ";
    cin >> colsA;
    cout << "\nEnter Matrix A:\n";
    inputMatrix(matrixC, rowsA, colsA);
    cout << "\nEnter number of rows for matrix B: ";
    cin >> rowsB;
    cout << "Enter number of columns for matrix B: ";
    cin >> colsB;
    if (colsA != rowsB) {
        cout << "Error: Number of columns in Matrix A must equal number of rows in Matrix B for multiplication." << endl;
    }
    else {
        
        cout << "\nEnter Matrix B:\n";
        inputMatrix(matrixD, rowsB, colsB);
        multiplyMatrices(matrixC, matrixD, product, rowsA, colsA, colsB);
        cout << "\nProduct of Matrix A and Matrix B:\n";
        displayMatrix(product, rowsA, colsB);
    }
   
    return 0;
}