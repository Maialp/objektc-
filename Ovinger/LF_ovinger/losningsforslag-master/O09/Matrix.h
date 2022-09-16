#pragma once
#include <ostream>

class Matrix {
	int rows, columns;
	// double * data; // Enkeltpeker: Langt array
	double **data; // Dobbeltpeker: Array av array
	double &at(int row, int column);
	double at(int row, int column) const;

public:
	explicit Matrix(int N); // explicit er ikke del av pensum, men vi trenger det for a fa oppforselen vi onsker. explicit hindrer implisitte konverteringer
	Matrix(int rows, int columns, double fill = 0.0);
	Matrix(const Matrix &rhs);
	~Matrix();

	Matrix &operator=(Matrix rhs);

	int getRows() const { return rows; }
	int getColumns() const { return columns; }

	void set(int row, int column, double value);
	double get(int row, int column) const;
	double *operator[](int row);

	Matrix &operator+=(const Matrix &rhs);
	Matrix operator+(const Matrix &rhs) const;

	// Valgfrie oppgaver
	Matrix &operator-=(const Matrix &rhs);	   // Binary -(minus) and assign
	Matrix operator-(const Matrix &rhs) const; // Binary -(minus)
	Matrix operator-() const;				   // Unary -(minus)

	Matrix &operator*=(const Matrix &rhs);
	Matrix operator*(const Matrix &rhs) const;
	Matrix operator*(double rhs) const;
	Matrix &operator*=(double rhs);
};

std::ostream &operator<<(std::ostream &out, const Matrix &elem);

// Valgfri oppgave
Matrix operator*(double lhs, const Matrix &rhs); // Multipliser med en double pa venstre side
