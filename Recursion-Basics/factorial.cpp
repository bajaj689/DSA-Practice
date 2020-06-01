#include<stdio.h>
#include<iostream>

using namespace std;
int factorial(int n){

	if(n == 0)
		return 1;
	
	int smallfact = factorial(n-1);
	return n * smallfact;

}




int main(){


	int n;
	//Prob: Find factorial of a num
	cout << "Enter num: " << endl;
	cin >> n;	
	cout << "Factorial of " << n << " is " << factorial(n);




	return 0;

}
