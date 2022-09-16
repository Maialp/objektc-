#include "matrix.h"

Matrix::Matrix(int nRows, int nColumns){
    assert(nRows>0 && nColumns>0);
    rows = nRows;
    cols = nColumns;
    matrix = new double*[rows];

    for(unsigned int i = 0; i < (rows); i++){
        matrix[i] = new double[cols];
        for (unsigned int j = 0; j <cols; j++){
            matrix[i][j] =0;
        }
    }
}

Matrix::Matrix(int nRows): Matrix(nRows, nRows) {
    assert(nRows>0);
    for(int i =0; i < nRows; i++){
        for( int j =0; j < nRows; j++){
            if(i==j){
                 matrix[i][j] = 1;
            }
        }
    }
}





Matrix::Matrix(const Matrix & rhs){
    rows = rhs.getRows();
    cols = rhs.getColumns();
    matrix = new double*[rows];
    for(unsigned int i = 0; i < (rows); i++){
        matrix[i] = new double[cols];
        for (unsigned int j = 0; j <cols; j++){
            matrix[i][j] =rhs.get(i,j);
        }
    }
}

Matrix::~Matrix(){
    delete[] matrix;
}

double Matrix::get(int row, int col) const {
    double val = matrix[row][col];
    return val;
}

void Matrix::set(int row, int col, double value){
    matrix[row][col] = value;
}

ostream& operator<<(ostream& os, const Matrix& p){
    int rows = p.getRows();
    int cols = p.getColumns();
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<cols; j++){
            double val = p.get(i, j);
            cout << setw(3)<<val;
        }
        cout << endl;
    }
    return os;
}

Matrix& Matrix::operator=(Matrix rhs){
    swap(this->rows, rhs.rows);
    swap(this->cols, rhs.cols);
    swap(this->matrix, rhs.matrix);
    return *this;
}

Matrix& Matrix::operator+=(Matrix rhs){
    for (unsigned int i = 0; i < rows; i++){
        for (unsigned int j = 0; j <cols; j++){
            matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix rhs){
    //Matrix a = (*this += rhs);
    Matrix a = *this;
    Matrix c{(a += rhs)};
    return c;
}