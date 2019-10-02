/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 09/07/2019
Description:
To find the sum of maximum path
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>
#include <climits>
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
	// Purpose - To find maximum path sum of the given triangle
	// input - TAkes the file name as input
	// output - REturns maximum path sum in output file
	int count= 0,height;
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
				height = num[0];
				count++;
			}	
		}
		myfile.close();
	}

	else cout << "Unable to open file"; 
	// cout<<"Height = "<<height<<endl;
	// int sum = ans[0][0];
	// int check =0;

	for (int i = 1; i <height; i++)
	{
		for (int j = 0; j < i; j++)//ans[i].size()
		{
			int num1 = INT_MIN;
			int num2 = INT_MIN;	
			try
			{
				num1 = ans[i - 1][j] ;// check element above
				// cout<<"Num1 "<<num1<<" "<<i<<" "<<j<<endl;
			}
			catch (int e)
			{
				num1 = INT_MIN;
				// cout<<"Num1 "<<num1<<" "<<i<<" "<<j<<endl;
			}
			try
			{
				num2 = ans[i - 1][j-1] ;// check element above and one column left
				// cout<<"Num2 "<<num2<<" "<<i<<" "<<j<<endl;
			}
			catch (int e)
			{
				num2 = INT_MIN;
				// cout<<"Num2 "<<num2<<" "<<i<<" "<<j<<endl;
			}
			if(num1>num2) // comparing which element is higher and then adding
			{
				// cout<<"Num1 "<<num1<<" "<<i<<" "<<j<<endl;
				ans[i][j]+= num1;
			}
			else
			{
				// cout<<"Num2 "<<num2<<" "<<i<<" "<<j<<endl;
				ans[i][j]+= num2;
			}
		}
		int j = i;// Corner case when there is no element exactly above the element
		ans[i][j] = ans[i][j] + ans[i - 1][j-1];
	}
	// for(int i=0;i<ans.size();i++){
		// for(int j=0;j<ans[i].size();j++){
			// cout<<ans[i][j]<<" ";
		// }
		// cout<<"\n";
	// }
	int maximum = INT_MIN;
	for(int j= 0 ;j<height ; j++)
	{
		maximum = max(maximum,ans[height-1][j]); //Finding the max element in last row as we have addition of all.
	}
	// cout<<maximum;
	ofstream outfile;//Output to new output.txt file in same location.
	outfile.open ("output3.txt");
	outfile << maximum;
	outfile.close();
	return 0;
}