//TicTacToe Game CPP program
#include <iostream>
#include <vector>

using namespace std;

vector<string> board = {"-", "-", "-", "-", "-", "-", "-", "-", "-"};

void printBoard() {
    cout << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

void takeTurn(string player) {
    cout << player << "'s turn. Choose a position from 1-9: ";
    int position;
    cin >> position;
    position -= 1; 

    
    while (position < 0 || position > 8 || board[position] != "-") {
        cout << "Invalid input or position already taken. Choose a different position: ";
        cin >> position;
        position -= 1; 
    }
    board[position] = player; 
    printBoard(); 
}

bool checkWin() {

    if ((board[0] == board[1] && board[1] == board[2] && board[0] != "-") ||
        (board[3] == board[4] && board[4] == board[5] && board[3] != "-") ||
        (board[6] == board[7] && board[7] == board[8] && board[6] != "-")) {
        return true;
    }
   
    if ((board[0] == board[3] && board[3] == board[6] && board[0] != "-") ||
        (board[1] == board[4] && board[4] == board[7] && board[1] != "-") ||
        (board[2] == board[5] && board[5] == board[8] && board[2] != "-")) {
        return true;
    }
  
    if ((board[0] == board[4] && board[4] == board[8] && board[0] != "-") ||
        (board[2] == board[4] && board[4] == board[6] && board[2] != "-")) {
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < board.size(); i++) {
        if (board[i] == "-") {
            return false; 
        }
    }
    return true;
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    printBoard();

    string currentPlayer = "X";
    bool gameOver = false;

    while (!gameOver) {
        takeTurn(currentPlayer);

        if (checkWin()) {
            cout << currentPlayer << " wins!" << endl;
            gameOver = true;
        } else if (checkTie()) {
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == "X") ? "O" : "X"; 
        }
    }

    cout << "Game over. Thanks for playing!" << endl;
    return 0;
}

