#include<iostream>
using namespace std;
char Ai_symbol;
char human_symbol;
void display(char board[3][3]){
    for (int i=0;i<3;i++){
        for(int j=0; j<3;j++){
            cout<<" "<<board[i][j]<<" ";
            if(j<2) cout<<"|";
            
        }
        cout<<endl;
        if(i<2) cout<<"-----------"<<endl;
        ;
    }
}
char checkwin( char board[3][3]){
    for(int i=0;i<=2;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] &&  board[i][0]!=' ' ){
            return board[i][0];
        }
    }
      for(int j=0;j<=2;j++){
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j] &&  board[0][j]!=' ' )
   {return board[0][j];}
}
if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' '){
    return board[0][0];
} 
if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' '){
   return board[0][2]; 
}
  for(int i=0;i < 3;i++){
        for (int j = 0; j < 3; j++)
        {
        if(board[i][j]==' '){
            return ' ';
        }
        }
      
   }
   

     

 return 'D';


}
int minimax(char board[3][3], bool isMaximizing) {
    char result = checkwin(board);

    if (result == Ai_symbol) return 1;
    if (result == human_symbol) return -1;
    if (result == 'D') return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = Ai_symbol;
                    int score = minimax(board, false);
                    board[i][j] = ' ';
                    if (score > bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = human_symbol;
                    int score = minimax(board, true);
                    board[i][j] = ' ';
                    if (score < bestScore) bestScore = score;
                }
            }
        }
        return bestScore;
    }
}
int main(){
   char board[3][3];
   
   
   for(int i=0;i < 3;i++){
        for (int j = 0; j < 3; j++)
        {
        board[i][j]=' '; 
        }
        
   }
 
cout<<"Select your symbol: X/O";
cin>>human_symbol;


 if(human_symbol=='X'){
    cout<<"human symbol ="<<human_symbol<<endl;
    Ai_symbol='O';
    cout<<"Ai symbol="<<Ai_symbol<<endl;
 }
 else if(human_symbol=='O'){
    cout<<"human symbol ="<<human_symbol<<endl;
    Ai_symbol='X';
    cout<<"Ai symbol="<<Ai_symbol<<endl;
 }
 else{
    cout<<"Invalid choice";
 }
char currentturn;
currentturn=human_symbol;
 while (true)
 {
display(board);
int i;
int j;

if(currentturn==human_symbol)
  {  while(true){  
       cout<<"Enter row value :"<<endl;
       cin>>i;
       cout<<"Enter column value :"<<endl;
        cin>>j;
        cout<<"Your move"<<endl;
         if (i>=0 && i<3 && j>=0 && j<3 && board[i][j]==' ' ){
         board[i][j]=human_symbol;
          
          currentturn=Ai_symbol;
          break;
              }
         else{
         cout<<"Invalid Position";
             }
          }

}
    
else {
    cout<<"Ai move"<<endl;
    
    int bestScore = -1000;
    int bestRow = -1, bestCol = -1;

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (board[x][y] == ' ') {
                board[x][y] = Ai_symbol;
                int score = minimax(board, false);
                board[x][y] = ' ';

                if (score > bestScore) {
                    bestScore = score;
                    bestRow = x;
                    bestCol = y;
                }
            }
        }
    }

    board[bestRow][bestCol] = Ai_symbol;
    currentturn = human_symbol;
}
char Result;
Result=checkwin(board);

if(Result==human_symbol){
    display(board);
    cout<<"You Win";
    break ;
}
else if(Result==Ai_symbol){
     display(board);
    cout<<"Computer Wins";
    break;
}
else if(Result=='D'){
     display(board);
    cout<<"Game Withdraw";
    break;
}

}
}

