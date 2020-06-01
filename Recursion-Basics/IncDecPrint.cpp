#include<stdio.h>
#include<iostream>

using namespace std;
void incPrint(int n){

	if(n <= 0)
		return;
	
	incPrint(n-1);
	cout << n << endl;
	return;

}

void decPrint(int n){

	
	if(n <= 0)
	    return;	   

	cout << n << " ";
	decPrint(n-1);
	return;

}


int main(){


	int n;
	//Prob: Find factorial of a num
	cout << "Enter num: " << endl;
	cin >> n;	
	cout << "Inc print of " << n << " is: " << endl;
	incPrint(n);
	
	cout << "Dec print of " << n << " is: " << endl;
	decPrint(n);
	
	




	return 0;

}
