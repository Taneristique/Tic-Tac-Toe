#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;
class tictactoe{
			char us;
			char cs;
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
				int i,j,c; 
			
				for(i=0;i<8;i++){ //then check if user or computer wins
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
					print_table();
				}
				else{
					computer_plays(); //recursive function to make computer move a legal move 
				}
				}
		
			public:
			void startgame(int luck){
				cout<<"			Welcome to the Tic-Tac-Toe\n";
				cs=luck==0?'x':'o';
				us=cs=='x'?'o':'x';
				system("color 2F");
				cout<<endl<<"User You Are Playing With "<<us<<endl;
			}
	
				
				char board[3][3];
			
			
				void print_table(void){
					for(int i=0;i<3;i++){
						cout<<"\n-------\n";
						for(int j=0;j<3;j++){
							cout<<"|"<<board[i][j]; 
						}
							cout<<"|";
					}
					cout<<"\n-------\n";
	
				}
				void user_plays(){
					check();
					int u_r,u_c;
					cout<<endl<<"Please write the index of row that you want to play : ";
					cin>>u_r; 
					cout<<endl<<"Please write the index of column that you want to play : ";
					cin>>u_c;
					cout<<endl;
				
					if(board[u_r][u_c]!='x'&&board[u_r][u_c]!='o' ){//check if the move is legal
						board[u_r][u_c]=us;
						print_table();
						computer_plays();
				}
	else{
		user_plays();//recursive function to make user move a legal move 
	}
			}
		}t;
int main(int argc, char** argv) {
		srand(time(NULL));
		t.print_table();
		t.startgame(rand() %2);
		while(true){
		 /*as you can see the same functions with c exist in c++ such as scanf ,printf, exit e.t.c I copied c code for most part of this code.However I used a class named tictactoe
		   as different from c version. And also this time user starts before computer. 
		 */
					t.user_plays();	
		}
		cout<<"\n";
	return 0;
}
