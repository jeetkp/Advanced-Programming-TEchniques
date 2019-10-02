/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 09/07/2019
Description:
To find the maximum product of 4 continous number in a 2D array
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
vector< vector<int> > ans;

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

vector<int> split(string str)
{//Funtion to Split the String on space delimiter
	// Purpose - To split the string on basis of space
	// input - TAkes the string value
	// output - REturns split strings which are further converted to integers and returned
	vector<int> temp;
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
	temp.push_back(y);
	return temp;
}

int main (int argc,char** argv) 
{
	// Purpose - To find maximum product of four numbers
	// input - TAkes the file name as input
	// output - REturns maximum product
	int count= 0,rows,columns;
	string line;
	ifstream myfile(argv[1]);
	if (myfile.is_open())//Opening and Reading my the given file
	{			
		while ( getline (myfile,line) )
		{	
			vector<int> num = split(line);
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

	else cout << "Unable to open file"; 
	// cout<<"Rows = "<<rows<<"Columns = "<<columns<<endl;
	int greatest = 0;// TO Store Greatest PRoduct
	// vector<int> check;//Checking which 4 numbers are being multiplied,
	for(int i=0;i<rows ; i++)
	{
		for(int j=0;j<columns; j++)
		{
			if(j< columns-3) // Checking consecutive elements in a row so j should be less than (length of columns) -3
			{
				int product = ans[i][j] * ans[i][j + 1] * ans[i][j + 2] * ans[i][j + 3];
				if(product>greatest)//checking if product is greater than product already stored.
				{
					greatest = product;
				}
			}
			if(i< rows-3) // Checking consecutive elements in a row so so rowth number should be less than (number of rows )-3
			{
				int product = ans[i][j] * ans[i + 1][j] * ans[i + 2][j] * ans[i + 3][j];
				if(product>greatest)//checking if product is greater than product already stored.
				{
					greatest = product;
				}
			}
			if (j < columns - 3 && i< rows-3)//Check main diagonal elements ,   so length of columns must be length of columns -3 and row should be less than number of rows -3
            {
				int product = ans[i][j] * ans[i + 1][j + 1] * ans[i + 2][j + 2] * ans[i + 3][ j + 3];
				if(product>greatest)//checking if product is greater than product already stored.
				{
					greatest = product;
				}
			}
			
			if (i > 3 && i< rows-3)//Check anti diagonal elements ,  rows should be greater than 3 since we are going reverse and row should be less than number of rows -3
			{
				int product =  ans[i][j] * ans[i + 1][j - 1] * ans[i + 2][j - 2] * ans[i + 3][j - 3];
				if(product>greatest)//checking if product is greater than product already stored.
				{
					greatest = product; 
				}
			}
		}
    }
	ofstream outfile;//Output to new output.txt file in same location.
	outfile.open ("output2.txt");
	outfile << greatest;
	outfile.close();
	return 0;
}