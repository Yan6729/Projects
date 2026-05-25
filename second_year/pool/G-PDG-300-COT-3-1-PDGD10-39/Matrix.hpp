/*
** EPITECH PROJECT, 2026
** snd_year_pool
** File description:
** Matrix
*/

#ifndef MATRIX_HPP_
    #include <iostream>
    #include <string>
    #include <functional>
    #include "Array.hpp"
    #define MATRIX_HPP_

template <unsigned int nb_rows, unsigned int nb_columns>
class Matrix {
    public:
        double operator()(unsigned int row, unsigned int col) const {
            return _matrix[row][col];
        };
        double &operator()(unsigned int row, unsigned int col) {
            return _matrix[row][col];
        }

        Matrix() {
            for (unsigned int a = 0; a < nb_rows; a++) {
                for (unsigned int b = 0; b < nb_columns; b++) {
                    _matrix[a][b] = 0;
                }
            }
        }

        template <unsigned int column>
        Matrix<nb_rows, column> operator*(const Matrix<nb_columns, column>& other) const {
            Matrix<nb_rows, column> result;

            for (unsigned int a = 0; a < nb_rows; a++) {
                for (unsigned int b = 0; b < column; b++) {
                    for (unsigned int c = 0; c < nb_columns; c++) {
                        result(a, b) += this->_matrix[a][c] * other(c, b);
                    }
                }
            }
            return result;
        }


       template <unsigned int column>
        Matrix& operator*=(const Matrix<nb_columns, column>& other) {
            *this = *this * other;
            return *this;
        }

    private:
        double _matrix[nb_rows][nb_columns];
};

template <unsigned int row, unsigned int colum>
std::ostream& operator<<(std::ostream& redirect, const Matrix<row, colum> other) {
    redirect << "[[";

    std::size_t _row;
    std::size_t _col;
    
    for (_row = 0; _row < row; _row++) {
        for (_col = 0; _col < colum; _col++) {
            redirect << other(_row, _col);
            if (_col < colum-1)
                redirect << ", ";
        }
        redirect << "]";
        if (_row < row-1) {
            redirect << ", [";
        }
    }
    redirect << "]";
    return redirect;
}

#endif /* !MATRIX_HPP_ */
