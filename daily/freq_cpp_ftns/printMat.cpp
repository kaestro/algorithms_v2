#ifndef PRINTMAT
#define PRINTMAT

#include <vector>
#include <iostream>

using vi = std::vector<int>;
using vvi = std::vector<vi>;

void printMat(const vvi& matrix) {
    if (matrix.size() == 0) return;
    int row_size = matrix.size(), col_size = matrix[0].size();

    for (int row = 0; row < row_size; ++row) {
        std::cout << "[";
        for (int col = 0; col < col_size - 1; ++col) {
            std::cout << matrix[row][col] << "\t";
        }
        std::cout << matrix[row][col_size - 1] << "]\n";
    }
    std::cout << std::endl;
}

#endif