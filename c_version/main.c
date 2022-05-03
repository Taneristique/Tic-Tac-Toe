#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*FUNCTION PROTOTYPES*/
void drawtable(void); //will print game board which is 3x3 matrix
int check(void); //check if game is over with any result
void user_plays(void);// make user play a move 
void computer_plays(void);//make computer play a random move
/*GLOBAL VARIABLES*/
char cs; //sign that computer tries to order correctly
char us;		//sign that user tries to order correctly
char board[3][3];//game board matrix
/*FUNCTIONS*/
int main(int argc, char *argv[]) {
	srand(time(NULL));//using current time as seed for random generator
	int random_v= rand() % 2; //create a random table between 0 and 2->2 is excluded! The number generated will determine sign of both players.
	cs=random_v==0?'o':'x';
	us=cs=='o'?'x':'o';
	while(1){
		computer_plays();
		user_plays();
		
	}
	return 0;
}
void drawtable(void){
	int i,j;
	for(i=0;i<3;i++){
		printf("\n---------\n");
		for(j=0;j<3;j++){
			printf("|%c|",board[i][j]);
		}
	}
	printf("\n---------\n");//draw lowerbond of game board
}
int check(void){
	int l_c[]={
	board[0][0]==cs&&board[0][1]==cs&&board[0][2]==cs,
    board[1][0]==cs&&board[1][1]==cs&&board[1][2]==cs , 
    board[2][0]==cs&&board[2][1]==cs&&board[2][2]==cs , 
    board[0][0]==cs&&board[1][0]==cs&&board[2][0]==cs , 
    board[0][1]==cs&&board[1][1]==cs&&board[2][1]==cs , 
    board[0][2]==cs&&board[1][2]==cs&&board[2][2]==cs , 
    board[0][0]==cs&&board[1][1]==cs&&board[2][2]==cs , 
    board[0][2]==cs&&board[1][1]==cs&&board[2][0]==cs
	}; //cases that user lost
    int w_c[]={
	board[0][0]==us && board[0][1]==us && board[0][2]==us , 
    board[1][0]==us && board[1][1]==us && board[1][2]==us , 
    board[2][0]==us && board[2][1]==us && board[2][2]==us , 
    board[0][0]==us && board[1][0]==us && board[2][0]==us , 
    board[0][1]==us && board[1][1]==us && board[2][1]==us , 
    board[0][2]==us && board[1][2]==us && board[2][2]==us , 
    board[0][0]==us && board[1][1]==us && board[2][2]==us ,
    board[0][2]==us && board[1][1]==us && board[2][0]==us
	};//cases that user win
	int i,j;
	int c=0; 

	for(i=0;i<8;i++){ //check if user or computer wins
		if(w_c[i]==1){
			printf("\n You won:)\nPress a key to exit....");
			getch();
			exit(EXIT_SUCCESS);
		}
		else if(l_c[i]==1){	
			printf("\n You lost:(\nPress a key to exit....");
			getch();
			exit(EXIT_SUCCESS);
		}
	}
		for(i=0;i<3;i++){ //check if game is drawn
		for(j=0;j<3;j++){
			c+=board[i][j]==us||board[i][j]==cs?1:0;
		}
		}
			
	if(c==9){//if true then game will be drawn
		printf("\nNobody wins it is draw!\nPress a key to exit....");
		getch();
		exit(EXIT_SUCCESS);
	}      
       	
	return 0;
}
void computer_plays(void){
	check();
	int r=rand() % 3;
	int c=rand() % 3;
	if(board[r][c]!='x'&&board[r][c]!='o' ){//check if the move is legal
		board[r][c]=cs;
		printf("\nComputer plays row %i and col %i\n",r,c);
		drawtable();
	}
	else{
		computer_plays(); //recursive function to make computer move a legal move 
	}
}
void user_plays(void){
	check();
	int u_r,u_c;
	printf("\nPlease write the index of row that you want to play : ");
	scanf("%i",&u_r); 
	printf("\nPlease write the index of column that you want to play : ");
	scanf("%i",&u_c);
	printf("\n");

	if(board[u_r][u_c]!='x'&&board[u_r][u_c]!='o' ){//check if the move is legal
		board[u_r][u_c]=us;
		drawtable();
	}
	else{
		user_plays();//recursive function to make user move a legal move 
	}
}
