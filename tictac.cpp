#include <iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentmarker='X';
int currentplayer=1;
int row,column;
bool draw=false;
void display_board(){
    system("cls");
    cout<<"*****WELCOME TO TIC-TAC-TOE GAME***** \n";
    cout<<"     |     |     \n";
    cout<<"   "<<board[0][0]<<" "<<"|"<<"  "<<board[0][1]<<"  "<<"|"<<" "<<board[0][2]<<endl;
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"   "<<board[1][0]<<" "<<"|"<<"  "<<board[1][1]<<"  "<<"|"<<" "<<board[1][2]<<endl;
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"   "<<board[2][0]<<" "<<"|"<<"  "<<board[2][1]<<"  "<<"|"<<" "<<board[2][2]<<endl;
    cout<<"     |     |     \n";
    
    
}
void playerturn(){
    int slot;
    cout<<"PLAYER"<<" "<< currentplayer<<" " <<(currentmarker)<<" choose your slot:";
    
    
    cin>>slot;
    switch(slot){
        case 1:
        row=0;column=0;
        break;
        case 2:
        row=0;column=1;
        break;
        case 3:
        row=0;column=2;
        break;
        case 4:
        row=1;column=0;
        break;
        case 5:
        row=1;column=1;
        break;
        case 6:
        row=1;column=2;
        break;
        case 7:
        row=2;column=0;
        break;
        case 8:
        row=2;column=1;
        break;
        case 9:
        row=2;column=2;
        break;
        default:
        cout<<"invalid choice";
        
        
    }
    if(currentmarker=='X'&& board[row][column]!='X'&& board[row][column]!='O'){
            board[row][column]='X';
            currentmarker='O';
            currentplayer=2;
        }
        else if(currentmarker=='O'&& board[row][column]!='X'&& board[row][column]!='O'){
            board[row][column]='O';
            currentmarker='X';
            currentplayer=1;
        }
        else{
            cout<<"Slot already filled!! Please choose another slot!";
            playerturn();
        }
        display_board();

}
bool gameover(){
    for(int i=0;i<3;i++)
    if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]|| board[0][i]==board[1][i]&&board[1][i]==board[2][i])
    return false;
    
    if(board[0][0]==board[1][1]&&board[1][1]==board[2][2] || board[0][2]==board[1][1]&&board[1][1]==board[2][0])
        return false;
    
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
if(board[i][j]!='X'&&board[i][j]!='O')
        return true;

        
        draw=true;
        return false;
        }
    

    


int main() {
    
   while(gameover()) {
    display_board();
    playerturn();
    gameover();
   }
   if(currentmarker=='O'&& draw==false){
   cout<<"Player 1(x) won!! ";
   cout<<"CONGRATULATIONS!!";
   }
  else if(currentmarker=='X'&& draw==false){
   cout<<"Player 2(o) won!!";
   cout<<"CONGRATULATIONS!!";
   }
   else{
   cout<<" It's a Draw!";
   }
    
    
    return 0;
}