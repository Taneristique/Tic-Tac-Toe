import random
import sys
c_s=random.randint(0,1)     #sign of computer depends on a random number in range [0,1] 
cs='x' if c_s==1 else 0     #sign of computer
us='o' if cs=='x' else 'x'  #sign of user 
board=[['','',''],['','',''],['','','']]

def check():
    l_c=[
    board[0][0]==cs and board[0][1]==cs and board[0][2]==cs,
    board[1][0]==cs and board[1][1]==cs and board[1][2]==cs , 
    board[2][0]==cs and board[2][1]==cs and board[2][2]==cs , 
    board[0][0]==cs and board[1][0]==cs and board[2][0]==cs , 
    board[0][1]==cs and board[1][1]==cs and board[2][1]==cs , 
    board[0][2]==cs and board[1][2]==cs and board[2][2]==cs , 
    board[0][0]==cs and board[1][1]==cs and board[2][2]==cs , 
    board[0][2]==cs and board[1][1]==cs and board[2][0]==cs
    ] #cases where user lost
    w_c=[
    board[0][0]==us and board[0][1]==us and board[0][2]==us , 
    board[1][0]==us and board[1][1]==us and board[1][2]==us , 
    board[2][0]==us and board[2][1]==us and board[2][2]==us , 
    board[0][0]==us and board[1][0]==us and board[2][0]==us , 
    board[0][1]==us and board[1][1]==us and board[2][1]==us , 
    board[0][2]==us and board[1][2]==us and board[2][2]==us , 
    board[0][0]==us and board[1][1]==us and board[2][2]==us ,
    board[0][2]==us and board[1][1]==us and board[2][0]==us
    ] #cases where user win
    """used list comprehensions to simplifying code"""
    w=[w_c[i]==True for i in range(len(w_c))]
    l=[l_c[i]==True for i in range(len(l_c))]
    if(any(w)):   #if any member of winning function w is true prints victory message and wants an input from user than closes game 
        print("\nYou won:)")
        input("press any key to exit")
        sys.exit()
    elif(any(l)): #if any member of losing function w is true prints defeat message and wants an input from user than closes game
        print("\nYou lost:(")
        input("press any key to exit")
        sys.exit()

    c=0 #counter 
    for i in range(3):#check if there is draw
        for j in range(3):
            if board[i][j]!='':
                c+=1
            else:
                pass 
    if(c==9):
        print("draw")
        sys.exit()
    return 0 #means game continues
def drawboard():
    for i in range(3):
        print("\n---------")
        for j in range(3):
            print('|',end="")
            print(board[i][j],end='|')
    print("\n---------")

def user_plays():
    check()
    u_r=int(input("\nPlease give a row number : "))
    u_c=int(input("\nPlease give a col number : "))
    if board[u_r][u_c]=='':
        board[u_r][u_c]=us
        return drawboard()
    else:
        return user_plays()
def computer_plays():
    check()
    r=random.randint(0,2)
    c=random.randint(0,2)
    print("computer plays row  ",r, " col ",c,"\n")
    if board[r][c]=='':
        board[r][c]=cs 
        return drawboard()
    else:
        return computer_plays()
if __name__=='__main__':
    print("Welcome to Tic-Tac-Toe:)\nCreated by Taneristique\n")
    while True:
        computer_plays()
        user_plays()
