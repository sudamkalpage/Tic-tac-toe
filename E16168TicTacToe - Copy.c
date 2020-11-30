/*
	CO222-2019 Lab05
	Author: E16168

	TicTacToe game
*/
#include<stdio.h>
#include<stdlib.h>

#define SIZE 3

void scanBoard(int a[SIZE][SIZE]);
void printBoard(int b[SIZE][SIZE]);
int getWinner(int b[SIZE][SIZE]);

int main(){

	int inBoard[SIZE][SIZE];	//declaring an array

	printf("Please enter the board:\n");
	scanBoard(inBoard);	//scanBoard
	printf("Here is the board:\n");
	printBoard(inBoard);	//printBoard
	

	int winner;
	winner=getWinner(inBoard);
	//printf("%d\n",winner);
	
	//printing the result
	if(winner==0)	
		printf("Noughts win\n");
	else if(winner==1)
		printf("Crosses win\n");
	else
		printf("There are no winners\n");
	
	
	return 0;
}


//scan function
void scanBoard(int board[SIZE][SIZE]){
	//check if the input is 0 || 1 || 2
	//else give the error message "Enter valid input." and terminate the program
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			scanf("%d",&board[i][j]);	
		}
	}
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			if (!((board[i][j]==0)||(board[i][j]==1)||(board[i][j]==2)))
				printf("Enter valid input.\n");	
				//exit(0);
		}
	}
}


//print function
void printBoard(int board[SIZE][SIZE]){
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			if (board[i][j]==0)
				printf("O ");
			if (board[i][j]==1)
				printf("X ");
			if (board[i][j]==2)
				printf(". ");
		}
		printf("\n");
	}	
	//printing board
}


//find the winner of the game
//assume both two players can't win the game at the same time. It can't happen in a real game
int getWinner(int board[SIZE][SIZE]){
	
	int winner = 2;	
	
	//if winner is Noughts, winner = 0
	//if winner is Crosses, winner = 1
	//if there is no winner, winner = 2
	
	//change number 2's to 4(because 1+1+1=3,3<4)
	for (int i=0;i<SIZE;i++){
		for (int j=0;j<SIZE;j++){
			if (board[i][j]==2)
				board[i][j]=4;
		}
	}
	
/*   R1 R2 R3   D1
  C1 .   .   . 
  C2 .   .   .
  C3 .   .   .
                D2  
  */
	int done=0;
	int prodr[SIZE];//r-rppws
	int sumr[SIZE];
	int prodc[SIZE];//c-columns
	int sumc[SIZE];
	for(int j=0;j<SIZE;j++){
		prodr[j]=1;
		sumr[j]=0;
		for (int i=0;i<SIZE;i++){
			prodr[j]=prodr[j]*board[j][i];
			sumr[j]=sumr[j]+board[j][i];
		}

		if (prodr[j]==1){
			winner = 1;
			done=1;
		}
		else if (sumr[j]==0){
			winner = 0;
			done=1;
		}
	}
	for(int j=0;j<SIZE;j++){
		prodc[j]=1;
		sumc[j]=0;
		for (int i=0;i<SIZE;i++){
			prodc[j]=prodc[j]*board[j][i];
			sumc[j]=sumc[j]+board[j][i];
		}
		if (prodc[j]==1){
			winner = 1;
			done=1;
		}
		else if (sumc[j]==0){
			winner = 0;
			done=1;
		}

	}
	int d1sum=0,d2sum=0;
	int d1prod=1,d2prod=1;
	for (int i=0;i<SIZE;i++){
		d1prod=d1prod*board[i][SIZE-1-i];
		d1sum=d1sum+board[i][SIZE-1-i];
	}
	for (int i=0;i<SIZE;i++){
		d2prod=d2prod*board[i][i];
		d2sum=d2sum+board[i][SIZE-1-i];
	}
	if (d1prod==1||d2prod==1){
			winner = 1;
	}
	else if (d1sum==0||d2sum==0){
			winner = 0;
		}
	if (done!=1)
		winner = 2;

/*//for size==3
	int r1,r2,r3,c1,c2,c3,d1,d2=0;
	for (int i=0;i<SIZE;i++)
		r1=r1+inBoard[0][i];
	for (int i=0;i<SIZE;i++)
		r2=r2+inBoard[1][i];
	for (int i=0;i<SIZE;i++)
		r3=r3+inBoard[2][i];
	for (int i=0;i<SIZE;i++)
		c1=c1+inBoard[i][0];
	for (int i=0;i<SIZE;i++)
		c2=c2+inBoard[i][1];
	for (int i=0;i<SIZE;i++)
		c3=c3+inBoard[i][2];
	for (int i=0;i<SIZE;i++)
		d1=d1+inBoard[i][2-i];
	for (int i=0;i<SIZE;i++)
		d2=d2+inBoard[i][i];
					
	if((r1==0)||(r2==0)||(r3==0)||(c1==0)||(c2==0)||(c3==0)||(d1==0)||(d2==0))
		printf("winner noughts\n");
	else if((r1==3)||(r2==3)||(r3==3)||(c1==3)||(c2==3)||(c3==3)||(d1==3)||(d2==3))
		printf("winner crosses\n");
	else
		printf("no winner \n");
		
	/*printf("c1: %d\n",c1);
	printf("c2: %d\n",c2);
	printf("c3: %d\n",c3);
	printf("r1: %d\n",r1);
	printf("r2: %d\n",r2);
	printf("r3: %d\n",r3);
	printf("d1: %d\n",d1);
	printf("d2: %d\n",d2);*/
	
	return(winner);
}
