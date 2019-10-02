/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 09/15/2019
Description:
To write down the functions derfined in header file class
*/
#include "ECE_Matrix.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int stoi(string str) 
{//Function to convert Integer in form of sting to integer datatype
	// Purpose - To convert STring interger to integer
	// input - TAkes the string integer value as user input
	// output - REturns integer value as output
	int num=0;
	
	for(unsigned int i=0;i<str.length();i++)
	{
		if((str[i]-'0' <0 || str[i]-'0'>9) && (str[i] != ' ')){
			continue;
		}
		num=num*10+(str[i]-'0');
	}
	return num;
	
}

vector<double> split(string str)
{//Funtion to Split the String on space delimiter
	// Purpose - To split the string on basis of space
	// input - TAkes the string value
	// output - REturns split strings which are further converted to integers and returned
	vector<double> temp;
	string st="";
	for(unsigned int i=0;i<str.length();i++){
		if(str[i] != ' '){
			st.push_back(str[i]);
		}
		else{
			int t = stoi(st);
			temp.push_back(t);
			st="";
		}
	}
	int y = stoi(st);
	//cout<<st<<" ";
	temp.push_back(double(y));
	return temp;
}

ECE_Matrix::ECE_Matrix(string fileName)
{
	// Purpose - To initialize a matrix based on data in file
	// input - TAkes file name
	// output - REturns matrix with data from file
	vector< vector<double> > ans;
	int count= 0,rows,columns;
	string line;
	ifstream myfile(fileName.c_str());
	if (myfile.is_open())//Opening and Reading my the given file
	{			
		while ( getline (myfile,line) )
		{	
			vector<double> num = split(line);
			if(count==1)
			{
				ans.push_back(num);
			}
			if(count==0)
			{
				rows = num[0];
				columns = num[1];
				count++;
			}	
		}
		myfile.close();
	}
	else
	{
		cout<<"Failed";
	}
	
	this->M = rows;
	this->N = columns;
	this->mat = ans;
}

ECE_Matrix::ECE_Matrix()
{
	// Purpose - To initialize a 0x0 matrix
	this->M=0;
	this->N=0;
}

ECE_Matrix::ECE_Matrix(int M, double val)
{
	// Purpose - To initialize a MxN 0 matrix
	mat.resize(M);
	
	for(int i=0;i<M;i++)
	{
		mat[i].resize(M);
	}

	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			mat[i][j]=val;
		}
	}

	
	this->M=M;
	this->N=M;
}

ECE_Matrix::ECE_Matrix(int M, int N, double val)
{
	// Purpose - To initialize a MxN matrix with all values as val
	mat.resize(M);
	
	for(int i=0;i<M;i++)
	{
		mat[i].resize(N);
	}
	
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			mat[i][j]=val;
		}
	}
	
	this->M=M;
	this->N=N;
	
}

ECE_Matrix ECE_Matrix::operator=(const ECE_Matrix& rhs) const
{
	// Purpose - To assign RHS matrix to LHS as function of =
	ECE_Matrix temp(rhs.M, rhs.N,0);
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			temp.mat[i][j]=rhs.mat[i][j];
		}
	}		
	
	return temp;
}

ECE_Matrix ECE_Matrix::operator-(double val) const
{
	// Purpose - To perform MAtrix - val calculation
	ECE_Matrix temp(this->M,this->N,0.0);
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			temp.mat[i][j]=this->mat[i][j]-val;
		}
	}
	
	return temp;
}

ECE_Matrix ECE_Matrix::operator+(double val) const
{
	// Purpose - To perform MAtrix + val calculation
	ECE_Matrix temp(this->M,this->N,0.0);
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			temp.mat[i][j]=this->mat[i][j]+val;
		}
	}
	
	return temp;
}


ECE_Matrix ECE_Matrix::operator*(double val) const
{
	// Purpose - To perform MAtrix * val calculation
	ECE_Matrix temp(this->M,this->N,0.0);
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			temp.mat[i][j]=this->mat[i][j]*val;
		}
	}
	
	return temp;
}

ECE_Matrix ECE_Matrix::operator/(double val) const
{
	// Purpose - To perform MAtrix / val calculation
	ECE_Matrix temp(this->M,this->N,0.0);
	if(val == 0)
	{
		return temp;
	}
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			temp.mat[i][j]=(this->mat[i][j])/(val);
		}
	}
	
	return temp;
}



ECE_Matrix ECE_Matrix::operator-(const ECE_Matrix rhs) const
{
	// Purpose - To perform MAtrix - Matrix calculation
	int max_M=this->M > rhs.M?this->M:rhs.M;
	int max_N=this->N > rhs.N?this->N:rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			left.mat[i][j]= this->mat[i][j];
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] - right.mat[i][j];
		}
	}
	
	return left;
}

ECE_Matrix ECE_Matrix::operator+=(const ECE_Matrix rhs)
{
	// Purpose - To perform MAtrix += Matrix calculation
	int max_M=this->M > rhs.M?this->M:rhs.M;
	int max_N=this->N > rhs.N?this->N:rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			left.mat[i][j]= this->mat[i][j];
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] + right.mat[i][j];
		}
	}
	this->M = left.M;
	this->N = left.N;
	this->mat = left.mat;
	return *this;
}

ECE_Matrix ECE_Matrix::operator-=(const ECE_Matrix rhs)
{
	// Purpose - To perform MAtrix -= Matrix calculation
	int max_M=this->M > rhs.M?this->M:rhs.M;
	int max_N=this->N > rhs.N?this->N:rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			left.mat[i][j]= this->mat[i][j];
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] - right.mat[i][j];
		}
	}
	this->M = left.M;
	this->N = left.N;
	this->mat = left.mat;
	return *this;
}


ECE_Matrix ECE_Matrix::operator+(const ECE_Matrix rhs) const
{
	// Purpose - To perform MAtrix + Matrix calculation
	int max_M=this->M > rhs.M?this->M:rhs.M;
	int max_N=this->N > rhs.N?this->N:rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			left.mat[i][j]= this->mat[i][j];
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] + right.mat[i][j];
		}
	}
	
	return left;
}

ECE_Matrix ECE_Matrix::transpose() const
{
	// Purpose - To perform MAtrix transpose
	ECE_Matrix left(this->N, this->M,0);
	
	for(int i=0;i<this->M;i++)
	{
		for(int j=0;j<this->N;j++)
		{
			left.mat[j][i] = this->mat[i][j];
		}
	}
	return left;
}


ostream& operator<<(ostream& output, const ECE_Matrix& dt)
{
	// Purpose - To perform << operations for Matrix class/
	for(int i=0;i<dt.M;i++)
	{
		for(int j=0;j<dt.N;j++)
		{
			output<<scientific << setw(12) << setprecision(3) <<dt.mat[i][j]<<" ";
		}
		output<<endl;
	}

	return output;
}

ECE_Matrix operator+(double val , const ECE_Matrix rhs) 
{
	// Purpose - To perform val + Matrix calculation as a friend function for class
	int max_M=rhs.M;
	int max_N=rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= val;
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] + right.mat[i][j];
		}
	}
	
	return left;
}

ECE_Matrix operator-(double val , const ECE_Matrix rhs) 
{
	// Purpose - To perform val - Matrix calculation as a friend function for class
	int max_M=rhs.M;
	int max_N=rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= val;
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] - right.mat[i][j];
		}
	}
	
	return left;
}

ECE_Matrix operator*(double val , const ECE_Matrix rhs) 
{
	// Purpose - To perform val * Matrix calculation as a friend function for class
	int max_M=rhs.M;
	int max_N=rhs.N;
	ECE_Matrix left(max_M, max_N,0);
	ECE_Matrix right(max_M, max_N,0);	
		
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= val;
		}
	}
	
	for(int i=0;i<rhs.M;i++)
	{
		for(int j=0;j<rhs.N;j++)
		{
			right.mat[i][j]= rhs.mat[i][j];
		}
	}
	
	for(int i=0;i<max_M;i++)
	{
		for(int j=0;j<max_N;j++)
		{
			left.mat[i][j]= left.mat[i][j] * right.mat[i][j];
		}
	}
	
	return left;
}