#include "matrix.hpp"
#include <iostream>
#include <fstream>
#include <string>
std::pair<Matrix, Matrix> read_matrices_from_file(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        exit(1);
    }

    size_t N;
    file >> N; 

    std::vector<std::vector<int>> matrix1(N, std::vector<int>(N));
    std::vector<std::vector<int>> matrix2(N, std::vector<int>(N));

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            file >> matrix1[i][j];
        }
    }

    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < N; ++j) {
            file >> matrix2[i][j];
        }
    }

    file.close(); 
    return {Matrix(matrix1), Matrix(matrix2)};
}
int main(int argc, char *argv[]) {
    std::string filename;
    std::cout << "Enter a file name: ";
    std::getline(std::cin, filename);
    auto [matrix1, matrix2] = read_matrices_from_file(filename);
    matrix1.print_matrix();
    matrix2.print_matrix();
    Matrix added_matrix = matrix1 + matrix2;
    added_matrix.print_matrix();
    Matrix multiplied_matrix = matrix1 * matrix2;
    multiplied_matrix.print_matrix();
    int sum_major = matrix1.sum_diagonal_major();
    int sum_minor = matrix1.sum_diagonal_minor();
    std::cout << "Sum of the main diagonal elements of the first matrix is: " << sum_major << std::endl;
    std::cout << "Sum of the secondary diagonal elements of the first matrix is: " << sum_minor << std::endl;
    int sum_major2 = matrix2.sum_diagonal_major();
    int sum_minor2 = matrix2.sum_diagonal_minor();
    std::cout << "Sum of the main diagonal elements of the second matrix is: " << sum_major2 << std::endl;
    std::cout << "Sum of the secondary diagonal elements of the second matrix is: " << sum_minor2 << std::endl;
    int matrix_choice;
    std::cout << "Enter the matrix you would like to swap rows with(1 for the first, or 2 for the second): ";
    std::cin >> matrix_choice;
    int row1, row2;
    std::cout << "Enter the rows you would like to swap(in the format: row1 row2): ";
    std::cin >> row1 >> row2;
    if(matrix_choice == 1){
        matrix1.swap_rows(row1, row2);
    }else{
        matrix2.swap_rows(row1, row2);
    }
    int matrix_choice_col;
    std::cout << "Enter the matrix you would like to swap columns with(1 for the first, or 2 for the second): ";
    std::cin >> matrix_choice_col;
    int col1, col2;
    std::cout << "Enter the columns you would like to swap(in the format: col1 col2): ";
    std::cin >> col1 >> col2;
    if(matrix_choice_col == 1){
        matrix1.swap_cols(col1, col2);
    }else{
        matrix2.swap_cols(col1, col2);
    }
    int matrix_num, row, col, value;
    std::cout << "Enter the matrix you would like to change, the row and column of value you would like to change, and new value(in the format: matrix# row col value): ";
    std::cin >> matrix_num >> row >> col >> value;
    if(matrix_num == 1){
        matrix1.set_value(row, col, value);
        matrix1.print_matrix();
    }else{
        matrix2.set_value(row, col, value);
        matrix2.print_matrix();
    }
    return 0;
}
