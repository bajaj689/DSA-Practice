#include<stdio.h>
#include<iostream>

using namespace std;

//Find the nth number in a Fibonacci series

int fibonacciAt(int n){

	//Assuming 0-indexed series	
	if(n == 0 || n == 1)
		return 1;

		
	int ans = fibonacciAt(n-1) + fibonacciAt(n-2);
	return ans;

}

int main(){


	int n;
	//Prob: Find factorial of a num
	cout << "Enter num: " << endl;
	cin >> n;	
	cout << "Fibonacci number at index: "<< n << "  is " << fibonacciAt(n);



	return 0;

}
