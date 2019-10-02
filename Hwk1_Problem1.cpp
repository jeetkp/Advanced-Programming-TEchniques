/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 08/24/2019
Description:
To find number of instances that 1's need to be added to a number.
*/
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{  
	/*
	Purpose - To count the addition of number of 1s that need to added
	input - TAkes the integer value as user input
	output - REturns the count of instances of 1 added.
	*/
	int n, count = 0;    
	std::cout<<"Enter integer number "; // Integer Number is Entered
	std::cin>>n;
	if(n<=0)
	{
		cout<<"Please enter a positive integer ";
		return 0;
	}
	while(n!=1)
	{
        if(n%7==0)
		{
            n=n/7;// If number is divisible 7, then we divide by 7.
        }
		else
		{
            n=n+1;// Else we add 1 and then add 1 to count of 1's
            count++;
        }
	}
	std::cout<<"Number of instances for ones to be added are "<<count; // Printing out the count
	return 0;				
}
