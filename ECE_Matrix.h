/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 09/15/2019
Description:
To write Header file to perform Matrix operations.
*/
#include <istream>
#include <ostream>
#include <vector>
#include <string>
using namespace std;

class ECE_Matrix
{
	public:
	int M; //Number of Rows.
	int N; // Number of columns
	vector<vector<double> > mat;
	ECE_Matrix();//Default Constructor to define empty matrix
	ECE_Matrix(int M, double val);//Default Constructor to construct MxN 0 matrix
	ECE_Matrix(int M, int N,double val);//Default Constructor to construct MxN matrix with each value as val
	ECE_Matrix(string fileName);//Default Constructor to construct MxN matrix with data given in file
	
	ECE_Matrix operator=(const ECE_Matrix& rhs) const; // Assignment operator to setup the matrix to LHS from RHS
	ECE_Matrix operator-(double val) const; // Subtractor overload to subtract val from matrix
	ECE_Matrix operator+(double val) const;// Addition overload to add val from matrix
	ECE_Matrix operator-(const ECE_Matrix rhs) const; // Subtractor overload to subtract one matrix  from matrix
	ECE_Matrix operator+(const ECE_Matrix rhs) const;// Subtractor overload to add one matrix with matrix
	ECE_Matrix operator*(double val) const;// Multiply operator to multiply each element of matrix with given val
	ECE_Matrix operator/(double val) const;// divide operator to devide each element of matrix with given val
	ECE_Matrix operator+=(const ECE_Matrix rhs);// += operator to add each element of matrix with given matrix
	ECE_Matrix operator-=(const ECE_Matrix rhs);// -= operator to add each element of matrix with given matrix
	ECE_Matrix transpose() const;// To transpose a matrix
	friend ECE_Matrix operator+(double val , const ECE_Matrix rhs);// TO perform constant + matrix additions
	friend ECE_Matrix operator-(double val , const ECE_Matrix rhs);// TO perform constant - matrix additions
	friend ECE_Matrix operator*(double val , const ECE_Matrix rhs);// TO perform constant * matrix additions
	// ECE_Matrix operator-(double val,const ECE_Matrix rhs) const;
	int getNum();
	friend ostream& operator<<(ostream& output, const ECE_Matrix& dt); // to be able to print stuff
}; 