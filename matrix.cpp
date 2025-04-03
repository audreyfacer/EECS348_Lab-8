#include "matrix.hpp"
#include <iostream>
// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:

Matrix::Matrix(size_t N) : size(N), data(N, std::vector<int>(N, 0)) {
    // initialize an empty NxN matrix
}
Matrix::Matrix(std::vector<std::vector<int>> nums) 
    : size(nums.size()), data(std::move(nums)) {}
// e.g. for a member function:
int Matrix::get_size() const {
    return size;
}
void Matrix::print_matrix() const {
    // print out the matrix
    for(size_t i = 0; i < size; ++i) {
        for(size_t j = 0; j < size; ++j) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
//retrieves a value at a certain index of the matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    return data[i][j];
}
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if(i >= size || j >= size){
        std::cerr << "Error: Invalid row or column indices.\n";
        return;
    }else{
        data[i][j] = n;
    }
}
Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix result(size); 

    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            result.data[i][j] = this->data[i][j] + rhs.data[i][j];
        }
    }
    
    return result;
}
Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix result(size);

    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = 0; j < size; ++j) {
            for (std::size_t k = 0; k < size; ++k){
                result.data[i][j] += this->data[i][k] * rhs.data[k][j];
            } 
        } 
    }

    return result;
}
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += data[i][i]; 
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    for (std::size_t i = 0; i < size; ++i) {
        sum += data[i][size - 1 - i]; 
    }
    return sum;
}

void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if(r1 < size && r2 < size){
        std::swap(data[r1], data[r2]);
    }else{
        std::cerr << "Error: Invalid row indices.\n";
        return;
    }
    print_matrix();
}
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if(c1 < size && c2 < size){
        for(size_t i = 0; i < size; ++i){
            std::swap(data[i][c1], data[i][c2]);
        }
    }else{
        std::cerr << "Error: Invalid column indices.\n";
        return;
    }
    print_matrix();
}