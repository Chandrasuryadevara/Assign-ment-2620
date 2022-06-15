#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
	int row, col;

	    cout << "Enter dimensions of the Matrix A (Row<space>coloum) :";
		cin >> row;
		cin >> col;
		Matrix P(row, col);
		
		Matrix S(row, col);
		cin >> P;
		cout << "Enter dimensions of the Matrix B (Row<space>coloum) :";
		cin >> row;
		cin >> col;
		int row1= row;
		int col1 = col;
		Matrix Q(row, col);
		cin >> Q;
		cout << "Enter dimensions of the Matrix C (Row<space>coloum) :";
		cin >> row;
		cin >> col;
		Matrix R(row, col);
		cin >> R;
		
		cout << "The Value of Matrix operation P + Q = ";
		cout << P+Q ;
		cout << "The value of Matrix opperation P x R - P = ";
		cout << (P*R)-P;
		S=P.create(S);
		cout << "The value of Matrix opperation (P+S) x R = ";
		cout << (P+S)*R;
		indicator(P);
 return 0;
}
