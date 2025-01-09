#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

void showBoard(vector<char>& board){

    cout << "-------------" << endl;
    for(int i = 0; i < 9; i += 3){
        cout << "| ";
        for(int j = 0; j < 3; j++)
            cout << board[i + j] << " | ";
        cout << endl << "-------------" << endl;
    }
}

bool checkWin(vector<char>& board, char symbol){
    for(int i = 0; i < 3; i++){
        if(board[i * 3] == symbol && board[i * 3 + 1] == symbol && board[i * 3 + 2] == symbol)
            return 1;
        if(board[i] == symbol && board[i + 3] == symbol && board[i + 6] == symbol)
            return 1;
    }

    if(board[0] == symbol && board[4] == symbol && board[8] == symbol)
        return 1;
    if(board[2] == symbol && board[4] == symbol && board[6] == symbol)
        return 1;

    return 0;
}

void aiMove(vector<char>& board, char symbol){
    int move;
    do{
        move = rand() % 9;
    } while (board[move] != ' ');
    board[move] = symbol;
}

int main(){

    vector<char> board(9, ' ');
    char symbol = 'X';
    int row, column;
    int gameMode;

    cout << "Welcome to Tic Tac Toe!!!" << endl;
    cout << "Select Game Mode: \n1. Player vs Player \n2. Player vs AI" << endl;
    cin >> gameMode;

    for(int turn = 0; turn < 9; turn++){
        
        showBoard(board);

        if(gameMode == 2 && symbol == 'O'){
            cout << "AI is making a move..." << endl;
            Sleep(2000);
            aiMove(board, symbol);
        } else {
            while(true){
                
                cout << "Player " << symbol  << ", enter a row (1-3) and a column (1-3)" << endl;
                cin >> row >> column;

                row--; column--;

                if(board[row * 3 + column] != ' ' || row < 0 || row > 2 || column < 0 || column > 2)
                    cout << "Invalid move. Try again!" << endl; 
                else
                    break;
            }

            board[row * 3 + column] = symbol;
        }
        
        if(checkWin(board, symbol)){
            showBoard(board);
            cout << "Player " << symbol << " wins!" << endl;
            return 0;
        }
    
        symbol = (symbol == 'X') ? 'O' : 'X';
    }

    showBoard(board);
    cout << "It's a draw!" << endl;
    
    return 0;
}