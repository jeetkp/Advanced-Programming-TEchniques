/*
Author: Jeet Kiran Pawani
Class: ECE6122
Last Date Modified: 09/05/2019
Description:
To find the possible pattern of the knights to sit around of theKing, where every 2 knoghts sum upto a fiboncacci numbers.
*/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> fibo;// To store the fibinacci series

int main()
{
	/*
	Purpose - To cfind the pattern in which the knights will sit around the King as per fibinacci numbers
	input - TAkes the integer value of number of knights as user input
	output - REturns first formation possible or if the formation is not possible. it will say no combination possible.
	*/
	int n,count=0,j;
    std::cout<<"Enter number of knights -";
    std::cin>>n;
	if(n<=0)
	{
		cout<<"Please enter positive integer values";
		return 0;
	}
    unsigned long arr[n];//Maintain the order of knights
    int flag = 0;//If possible combination found flag
    int a = 0, b=1;//For fibonacci number generation
    fibo.push_back(a);
    fibo.push_back(b);
    int sum_check = n+(n-1); //Defining this to find till max number that Fibonnacci series needs to ba calculated.
    int sum =0;
    while(sum<sum_check)// Generating Fibonnacci series
    {
        sum = a+b;
        fibo.push_back(sum);
        a=b;
        b=sum;
    }
    
    for(int i =0;i<n;i++)// Defining the array of Knights
    {    
        arr[i] = i+1;
        // std::cout<<arr[i]<<" ";
    }
	
	if(n==1)
	{
		cout<<"First Possible sequence Generated is - ";
		std::cout<<"K , "<<arr[n-1]<<endl;
		return 0;
	}
	
    do// Do while loop to check each permutation if the adjacents knights add up to fibonacci number
    {
        bool exists = 0;//Keep track of sum existing in the order.
        // std::cout<<"count - "<<count;
        // std::cout<<"\n";
        for(int i =0;i<n-1;i++)
        {
            // std::cout<<arr[i]<<" ";
            exists = 0;
            int sum = arr[i] + arr[i+1];
            for(int i1 =0;i1<=n*10;i1++)
            {
                if(sum == fibo[i1])
                {
                    exists = 1;//Checking each element in Fibinacci array
                }
            }
            if( exists==0)
            {
               break;//If does not exist break the loop and go to next permuation.
            }
        }
        if(exists == 1)// If it is possible for all adjacent knights just print out that combination and break that code.
        {   cout<<"The knights should sit clockwise as follows: ";
            for(j  =0;j<n-1;j++)
            {
                if(j==0)
				{
					std::cout<<"K , ";
				}
				std::cout<<arr[j]<<" , ";//Printing out the possible combination
            }
			if(j==n-1)
			{
				std::cout<<arr[j];
			}
            std::cout<<"\n";
			flag =1;//One pattern possible so setting flag to 1.
            break;
            
        }
        
        count++;
    } while (std::next_permutation(arr,arr+n)); //This gives all permutations possible.
    
    if(flag ==0)//If flag is still 0, there is no possible combination
    {
        cout<<"No solution found!";
    }
    return 0;
}