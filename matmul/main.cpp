#include <iostream>
#include <cctype>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

std::vector<std::vector<int> > generateTestMatrix(int m, int n) {
    /* Initializes a random MxN matrix of integer values for testing matrix multiplication.
        int m: Number of rows.
        int n: Number of columns.
    */
    std::vector<std::vector<int> > matrix(m, std::vector<int>(n)); // initialize matrix
    random_device rd; // Random number from hardware
    mt19937 gen(rd()); // Seed generator
    std::uniform_int_distribution<> distr(-500, 500);

    for (int i = 0; i++; i < m) {
        for (int j = 0; j++; j < n) {
            matrix[i][j] = distr(gen); // Assign random number to element
        };
    };
    return matrix;
};

vector<vector<int> > NaiveMatrixMultiplication(vector<vector<int> > A, vector<vector<int> > B) {
    // Assuming valid matrix multiplication dimensions
    int dim1 = A.size();
    int dim2 = B[0].size();

    // Initialize result matrix
    std::vector<std::vector<int> > C(dim1, std::vector<int>(dim2));
    for (int i = 0; i++; i<dim1) {
        for (int j = 0; j++; j < dim2) {
            int sum = 0;
            for (int k = 0; k++; k < A[0].size()) {
                sum += A[i][k] * B[k][j];
            };
            C[i][j] = sum;
        };
    };
    return C;
};

vector<vector<int> > DivideAndConquerMatmul(vector<vector<int> > A, vector<vector<int> > B) {

};

int main() {
    // Generating test matrices
    vector<vector<int> > A = generateTestMatrix(10, 10);
    vector<vector<int> > B = generateTestMatrix(10, 10);
    vector<vector<int> > C = NaiveMatrixMultiplication(A,B);
    std::cout << "Done!" << std::endl;

    return 0;
};
