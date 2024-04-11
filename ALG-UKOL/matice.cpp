#include <iostream>
#include <vector>

using namespace std;

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to add two matrices
vector<vector<int>> addMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows = matrix1.size();
    int cols = matrix1[0].size();
    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix1, const vector<vector<int>>& matrix2) {
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int cols2 = matrix2[0].size();
    vector<vector<int>> result(rows1, vector<int>(cols2));

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

int main() {
    // Example matrices
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};

    vector<vector<int>> matrix2 = {{9, 8, 7},
                                   {6, 5, 4},
                                   {3, 2, 1}};

    // Matrix addition
    cout << "Matrix Addition:" << endl;
    vector<vector<int>> sumResult = addMatrices(matrix1, matrix2);
    printMatrix(sumResult);

    // Matrix multiplication
    cout << "Matrix Multiplication:" << endl;
    vector<vector<int>> multiplyResult = multiplyMatrices(matrix1, matrix2);
    printMatrix(multiplyResult);

    return 0;
}