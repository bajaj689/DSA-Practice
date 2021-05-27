#include<iostream>
#include<cstdlib>
using namespace std;

/*
 *Notes:
	
1) Run code until certain condition is met, other than the number of times it is run
   while loop is used when we dont know how many times the loop should run. 
   Ex: Reading user input, Reading from a file to variable, server waiting for client request, daemons 

2) for loop requires new variable. More rigid syntax(But more understandable unlike while loop where post interation statement gets lost in the body of while).
   Used when its known how many times loops should run
   Ex: Reading array,

3) break : terminate from loop instantly

4) continue: terminate current iteration and move to next one
   while(part2){
	---
	---
	continue;
	part3 //will not be executed
	
   }

   for(part1; part2; part3){


    continue; //evaluates part 3 before checking part 2

   }
*/


int main(){

	//Problem 1:
	//A shop will give discount of 10% if the cost of purchased quantity is more than 1000.
	//Ask user for quantity
	//Suppose, one unit will cost 100.
	//Judge and print total cost for user.
	//

	int quantity;
	cin >> quantity;

	if(100*quantity > 1000){

		cout << (100*quantity) - ((100*quantity) * 10)/100;

	}
	else

		cout << 100*quantity <<endl;



	//Problem 2:
	//A school has following rules for grading system:
	//a. Below 25 - F
	//b. 25 to 45 - E
	//c. 45 to 50 - D
	//d. 50 to 60 - C
	//e. 60 to 80 - B
	//f. Above 80 - A
	//Ask user to enter marks and print the corresponding grade.


	//Problem 3:
	//Take input of age of 3 people by user and determine oldest and youngest among them.


	//Problem 4 :Write a program to print absolute vlaue of a number entered by user
	int num;
	cin >> num;
	cout << abs(num) << endl;

	cout << (-1)*(num) << endl;

	return 0;

}

