//Assignment 2 (Matrixes)
//This version moves the Matrix addition, subtraction and multiplication
#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using std::ostream;
using std::istream;

class Matrix {
public:

//**************************
	// default constructor
	Matrix();
	//**************************
	// overloaded constructor
	Matrix(int m, int n);
	//**************************
	// Other methods
	Matrix(const Matrix& B1);
	friend ostream& operator<<(ostream&, const Matrix&) ;
	friend istream& operator>>(istream&, const Matrix&);
	const int& operator()(int i, int j);
	const Matrix& operator=(const Matrix B);
	const Matrix& operator+=(Matrix B);
	const Matrix& operator-=(Matrix B);
	const Matrix& operator*=(Matrix B);
	const Matrix operator+( Matrix B)const;
	const Matrix operator-( Matrix B) const;
	const Matrix operator*( Matrix B)const ;
	void getDimensions(int& m, int& n);
	Matrix create(Matrix D);
	friend void indicator(Matrix P);
	//**************************
	//destructor
	~Matrix();




private:

	int** M;
	int m;
	int n;
	void setSize(int m, int n);





};







#endif //
