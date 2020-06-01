#include<stdio.h>
#include<iostream>

using namespace std;


void AddElementToBottomOfStack(Stack* top,int data){

	
	if(top == NULL)
	{
		push(top, data);
		return;
	}
	
	int temp = pop(top);
	AddElementToBottomOfStack(top, data);
	push(top,temp);

	return;

}




int main(){


	int n;
	//Prob: Find factorial of a num
	cout << "Enter num: " << endl;
	cin >> n;	




	return 0;

}
