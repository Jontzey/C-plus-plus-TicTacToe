#include <iostream>
#include <string>
using namespace std;

string playerMarker = "X";
string board[] = {" ", " "," "," "," "," "," "," "," ",};


// this is called 2d array. with each object is a winning condition
// so the first one ( 0,1,2) is a row
// [X] [X] [X]
// [ ] [ ] [ ]
// [ ] [ ] [ ]

// for the column (0,3,6)
// [X] [ ] [ ]                                      // [0] [1] [2]
// [X] [ ] [ ]  == for better visual presentation   // [3] [4] [5]
// [X] [ ] [ ]                                      // [6] [7] [8]
int winCondition[8][3]  = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // columns
        {0, 4, 8}, {2, 4, 6}   // side to side // each corner and middle to each other
};

///////// field variables////////
int temp = 0;
bool isGameOver = false;
int player;
int playerPlacement;
/////////////////////////
void showBoard(){
    for(int i = 0; i < 9; i++){
        std:: cout << "[" << board[i] << "]";
        temp++;
        if(temp == 3){
            std::cout<< endl;
            temp = 0;
        }
    }

    std:: cout << "*********" << endl << "*********" << endl ;
}
void play(){

    if(player == 0){

     std:: cout << "player 1" << endl;
    }
    if(player == 1){
        std:: cout << "player 2" << endl;

    }


    // visa text
    std:: cout << "Place your marker" << endl;
    // läs spelarens input
    std:: cin >> playerPlacement;
    // om spelarens input är utanför range 0-8

    while(playerPlacement < 0 || playerPlacement > 8){
        std:: cout << "The placement was out of range" << endl << "Try again" << endl;
        std:: cout << "Place your marker" << endl;
        // läs spelarens input
        std:: cin >> playerPlacement;
    }

    // kolla om nuvarande plats är empty i board
    if(board[playerPlacement] == " "){
        board[playerPlacement] = playerMarker;
    }else{
        while(true){
            std:: cout << "The placement was already taken" << endl << "Try again" << endl;
            std:: cout << "Place your marker" << endl;
            // läs spelarens input
            std:: cin >> playerPlacement;
            if(board[playerPlacement] == " "){
                board[playerPlacement] = playerMarker;
                break;
            }
        }
    }
    // byt spelare
    if(player == 0){
        player = 1;
        playerMarker = "O";
    }else if(player == 1){
        player = 0;
        playerMarker = "X";
    }
}

bool checkWin(){

    // looping each object in the winning condition to check if the pattern matches
    for(int i = 0; i < 8; i++){
        if(
                // check each object and if each element in that object matches
                // if index 0 == index 1 and index 1 == index 2, so X X X then its true;
                board[winCondition[i][0]] == board[winCondition[i][1]] &&
                board[winCondition[i][1]] == board[winCondition[i][2]] &&
                board[winCondition[i][0]] != " "
        ){
            return true;
        }
    }
    return false;
}
bool checkDraw(){


    for(int i = 0; i < 9; i++){
        if(board[i] == " "){
            return false; // if there is a empty spot return false;
        }
    }
    // check if no player has won
    if (!checkWin()) {
        return true;
    }

    return false;
}
int main() {

    // tic tac toe i c++

    while(!isGameOver){
        // shows the tic-tac-toe board
        showBoard();
        //play, here the player makes the input and also switches between the players
        play();
        // as we return a boolean value isGameOver will change depending on the return value
      isGameOver = checkWin() || checkDraw();
    }
    if(checkWin()){
        std:: cout <<"**" << "Player " << player << " has won **" << endl;
        showBoard();
    }else if(checkDraw()){
        std:: cout<<endl << "**" << "Its a DRAW" << "**" << endl;
        showBoard();
    }


    return 0;
}














