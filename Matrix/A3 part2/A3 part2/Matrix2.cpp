// Matrix .cc file (Member definition)
//Author: Chandra shekar suryadevara

// Header file for standard input output
// Header file for our (Matrix.h) header
#include <iostream>
#include <cassert>
#include "Matrix2.h"

using namespace std;
template <typename T>
// default constructor
Matrix2::Matrix() :m(2), n(2) {
	//Member intialization is done for number of rows and colums

	M = new T* [m];
	// we are allocating with size 2X2 by default - int **M;
	for (int i = 0; i < m; i++) {

		M[i] = new T[n];

	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}




}
//**************************
   // overloaded constructor
Matrix2::Matrix(int m, int n) {
	this->m = m;
	this->n = n;
	//We are inputing row and colums from parameters
	M = new T* [m];
	for (int i = 0; i < m; i++) {

		M[i] = new T[n];

	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}
	// Assigning the value of Array to zero




}
void Matrix::setSize(int m, int n) {

	if (this->m != m && this->n != n) {
		delete[] M;
		this->m = m;
		this->n = n;
		M = new T* [m];
		for (int i = 0; i < m; i++) {

			this->M[i] = new T[n];

		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			M[i][j] = 0;
		}
	}
}
Matrix::Matrix(const Matrix& B) {

	this->m = B.m;
	this->n = B.n;

	this->M = new int* [m];
	for (int i = 0; i < m; i++) {

		this->M[i] = new int[n];

	}
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			this->M[i][j] = B.M[i][j];
		}
	}


}
// element fuction is to obtain value int he matrix as per given indexes
const int& Matrix::operator()(int i, int j) {

	assert(i < m&& j < n);

	return M[i][j];

}
const Matrix& Matrix::operator=(const Matrix B) {
	if (B.M != this->M) {
		setSize(B.m, B.n);

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				this->M[i][j] = B.M[i][j];
			}
		}
	}
	return *this;
}


// the add function inputs a matrix and adds to the object matrix

const Matrix& Matrix::operator+=(Matrix B) {
	int row = B.m;
	int col = B.n;
	m = this->m;
	n = this->n;


	assert(m == row && n == col);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			this->M[i][j] = this->M[i][j] + B.M[i][j];
		}
	}


	return *this;

}
// the subtract function inputs a matrix and subtracts to the object matrix
const Matrix& Matrix::operator-=(Matrix B) {
	int row = B.m;
	int col = B.n;
	m = this->m;
	n = this->n;



	assert(m == row && n == col);


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			M[i][j] = M[i][j] - B.M[i][j];
		}
	}

	return *this;
}
// the multiply function inputs a matrix and multiplies to the object matrix
const Matrix& Matrix::operator*=(Matrix B) {
	int row = B.m;
	int col = B.n;
	assert(n == row);
	Matrix E(m, col);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < n; k++)
			{
				E.M[i][j] = E.M[i][j] + this->M[i][k] * B.M[k][j];
			}
		}
	}
	for (int k = 0; k < m; k++) {
		for (int z = 0; z < col; z++) {
			this->M[k][z] = E.M[k][z];
		}
	}

	return *this;
}
const Matrix Matrix::operator+(Matrix B)const {
	int row = B.m;
	int col = B.n;
	Matrix C(m, n);

	assert(m == row && n == col);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C.M[i][j] = this->M[i][j] + B.M[i][j];
		}
	}


	return C;

}
const Matrix Matrix::operator-(Matrix B) const {
	int row = B.m;
	int col = B.n;
	Matrix C(m, n);

	assert(m == row && n == col);

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			C.M[i][j] = this->M[i][j] - B.M[i][j];
		}
	}


	return C;

}
const Matrix Matrix::operator*(Matrix B) const {
	int row = B.m;
	int col = B.n;
	assert(n == row);
	Matrix C(m, col);
	for (int k = 0; k < m; k++) {
		for (int z = 0; z < col; z++) {
			C.M[k][z] = 0;
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < col; j++)
		{
			for (int k = 0; k < n; k++)
			{
				C.M[i][j] = C.M[i][j] + this->M[i][k] * B.M[k][j];
			}
		}
	}
	return C;

}
istream& operator>>(istream& input, const  Matrix& B) {
	for (int i = 0; i < B.m; i++)
	{
		for (int j = 0; j < B.n; j++) {
			cout << "Enter element at " << " [ " << i + 1 << " ] " << " [ " << j + 1 << " ] ";
			input >> B.M[i][j];


		}


	}
	return input;
}
ostream& operator<<(ostream& output, const  Matrix& B) {


	cout << "[";
	for (int i = 0; i < B.m; i++) {
		cout << (i == 0 || i == B.m ? "" : ",");

		for (int j = 0; j < B.n; j++) {
			output << B.M[i][j];
			cout << (j == B.n - 1 ? "" : " ");

		}

	}
	cout << "]" << endl;






	return output;

}

//**************************
	// Other methods
//Get dimension helps to get number of rows and colums

void Matrix::getDimensions(int& m, int& n) {
	m = this->m;
	n = this->n;
	cout << "The Dimensions of the matrix is " << m << " x " << n;

}

// the create function inputs Matrix and equals the object matrix to the input matrix and modify the input matrix first colum to zero(0)
Matrix Matrix::create(Matrix D) {

	int m = D.m;
	int n = D.n;

	for (int k = 0; k < m; k++) {
		for (int z = 0; z < n; z++) {
			D.M[k][z] = this->M[k][z];
		}
	}
	for (int u = 0; u < n; u++) {
		D.M[u][0] = 0;
	}


	return D;

}
void indicator(Matrix P) {
	if (P.m == P.n) {
		int q;
		Matrix H(P.m, P.n);
		H = P;

		cout << "Enter a positive integer n ";
		cin >> q;
		for (int i = 0; i < q - 1; i++) {

			H *= P;

		}
		cout << H;
	}
	else {
		cout << endl;
		cout << "The Matrix P is not a square matrix ";

	}

}
//**************************
	//destructor

Matrix::~Matrix() {
	if (M != nullptr) {

		for (int i = 0; i < m; i++) {
			delete M[i];
		}
	}

	delete[] M;

}
