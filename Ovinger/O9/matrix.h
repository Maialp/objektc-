#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Matrix{
    private:
        int rows;
        int cols;
        double** matrix;
    public:
        Matrix(int nRows, int nColumns);

        explicit Matrix(int nRows);
        Matrix(const Matrix & rhs);

        ~Matrix();
        double get(int row, int col) const;
        void set(int row, int col, double value); 
        int getRows() const{return rows;}
        int getColumns() const{return cols;}

        friend ostream& operator<<(ostream& os, const Matrix& p);
        Matrix& operator=(Matrix rhs);
        Matrix& operator+=(Matrix rhs);
        Matrix operator+(Matrix rhs);

};