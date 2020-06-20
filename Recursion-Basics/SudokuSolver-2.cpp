#include<stdio.h>
#include<bits/stdc++.h>

#include<iostream>
using namespace std;
//Base condition
//Finding next avail space
//checking 3*3 set for duplicate values
//Time complexity

int getNextAvailblePos(int Board[9][9], int* availRow, int* availCol){

	
	for(int i = 0; i < 9;i++){
	
		for(int j = 0; j < 9; j++){

			
			if(Board[i][j] == 0)//Available
			{
			
			    *availRow = i;
			    *availCol = j;
			    return 0;
			    //return i,j;	
			
			}
		}
	}

	return 1;	
}


bool canInsertNumAtPosXY(int Board[9][9], int num, int row, int col){

	//For row 
	//Check all values != -1 ===>  Board[row][y..0 to 8]
	for(int i = 0; i < 9; i++){
	
			if(Board[row][i] == num) return false;

			if(Board[i][col] == num) return false;
	
	}	
	//check in the 3*3 set
	
	int rootn = sqrt(9);
	int boxRow = row / rootn;
	int boxCol = col / rootn;
	int boxStartCellRow = boxRow * rootn;
	int boxStartCellCol = boxCol * rootn;
	for (int i = boxStartCellRow; i < boxStartCellRow + rootn; ++i) {
		for (int j = boxStartCellCol; j < boxStartCellCol + rootn; ++j) {
			if (Board[i][j] == num) return false;
		}
	}

	return true;


}

void PrintBoard(int Board[9][9], int d){


        cout << "Solution is :" << endl;
        for(int i = 0; i < d; i++){

                for(int j=0; j < d; j++){

                        printf("%4d",Board[i][j]);

                }
                printf("\n");
        }

        cout << endl;
        return;

}


bool solveSudoku(int Board[9][9]){


	//if(y == 9){//go to next row
	
//	     return solveSudoku(Board,x+1,0);

//	}

//	if(x == 9){
	     //processed entire board
//	     return true;
//	}

	//To find empty cell
	//if(Board[x][y] != 0)
	//	return solveSudoku(Board,x,y+1);

	int x = 0;
	int y = 0;
	if(getNextAvailblePos(Board,&x, &y))  //Used as BASE CONDITION
		return true;


	for(int num = 1; num <= 9; num++){
	
			
		if(canInsertNumAtPosXY(Board, num, x, y)){

			//Rest of the board will be filled by recursion
			Board[x][y] = num;
			if(solveSudoku(Board))
				return true;
			else
				Board[x][y] = 0;


		}

	}

	return false;

}

int main(){



	int Board[9][9] = {

	{5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}

	}; //With values given -- assume

	cout << "Input Board was: " << endl;
	PrintBoard(Board,9);

	
	if(solveSudoku(Board))
		PrintBoard(Board,9);
	else
		cout << "Failure" << endl;







	return 0;

}
