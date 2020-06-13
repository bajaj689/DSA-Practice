#include<stdio.h>
#include<iostream>
using namespace std;

const int N=16; //Some Max Board Size


//Possible moves -- Within Board && Not visited
//



bool KnightMove(int Board[N][N],int d, int moveNo, int CurrRow, int CurrCol){

	static int rowDir[8] = {2,1,-1,-2,-2,-1,1,2};
	static int colDir[8] = {1,2,2,1,-1,-2,-2,-1};
	
	if(moveNo == d*d)
	    return true;

	
	for(int i = 0; i < d; i++){

		int newRow = CurrRow + rowDir[i];
		int newCol = CurrCol + colDir[i];
		if(newRow < d && newRow >= 0 && newCol >= 0 && newCol < d && Board[newRow][newCol] == 0){

			//Valid Move
			Board[newRow][newCol] =  moveNo+1;

			if(KnightMove(Board, d, moveNo+1 , newRow, newCol)){
				return true;
			}	
			else
				Board[newRow][newCol] = 0; //BACK TRACKING
		}

	}

	return false;


}



void PrintBoard(int Board[N][N], int d){


	for(int i = 0; i < d; i++){
	
		for(int j=0; j < d; j++){

			printf("%4d",Board[i][j]);

		}
		printf("\n");
	}


	return;

}





int main(){


	int Board[N][N] = {0};
	Board[0][0] = 1;
	int d = 8;
	cout << "Enter the dimension(N) of your N * N board"<<endl;
	cin >> d;
	cout << "dimension is " << d <<endl;
	if(KnightMove(Board,d, 1, 0, 0))
	{
		//Function was able to do the Knight Moves
		//Print Board
		PrintBoard(Board, d);
	
	}
	else
	{
		printf("Sorry cant visit your board!\n");
	}

	return 0;
}
