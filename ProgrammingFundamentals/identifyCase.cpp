#include<iostream>
using namespace std;
int main(){

	//Problem 5:
	//Write a program to check whether a entered character is lowercase ( a to z ) or uppercase ( A to Z ).
	
	char var;
	cout << "Enter a char" << endl;
	cin >> var ;
	//cin >> var >> endl; //Error

	if(var >= 97 && var <= 122)
		cout << "lowercase" << endl;
	else if(var >=65 && var <= 90)
		cout << "uppercase" << endl;
	else
		cout << "invalid char" << endl;


}
