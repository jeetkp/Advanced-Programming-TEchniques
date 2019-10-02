/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 08/24/2019
Description:
Midpoint  implementation to find the evaluation of integral
*/
#include <stdio.h>
#include <iostream>
#include <iomanip> 

int main()
{   
	/*
	Purpose - To evaluate the integral using midpoint rule
	input - TAkes value of Beta and subdivisions as user input
	output - REturns final value of evaluated integral
	*/
    double beta ; // Value for beta
    unsigned long N;// No of subdivisions Subdivisions
	std::cout<<"Please enter a value for upper limit (beta) ";
	std::cin>>beta;
	std::cout<<"Please enter the number of subdivisions to use ";
	std::cin>>N;
	double deltaX= beta/N; //Delta x is the value required in midpoint formula. (Length of Each interval)
//   std::cout<<deltaX;
	double sum=0;
	for(unsigned long i =1 ; i<= N;i++)//Evalution of midpoint formula.
	{    
		double check = (i-1)*deltaX;  // VAlue of x being calculated in each interval. (i-1) being used as loop starts with 1 and mid point formula runs from 1 to N.
		double value = 4.0/((1+(check*check))); // Evaluation of function to be evaluated in integral
		sum = sum + (value*deltaX);
	}
	std::cout<<"The integral evaluates to "<<std::setprecision(16)<<sum;//Setting precision to the value of Integral
	return 0;
}