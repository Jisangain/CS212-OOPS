#include <iostream>
#include <vector>
using namespace std;
class TicTacToe {
private:
    vector<vector<char>> board;

public:
    // Constructor to initialize the 3x3 board
    TicTacToe() : board(3, vector<char>(3, ' ')) {}

    // Function to display the current state of the board
    void displayBoard() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i < 2) {
                cout << "---------" << endl;
            }
        }
        cout << endl;
    }

    // Function to make a move on the board
    int makeMove(int row, int col, char player) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            return 1;
        } else {
            cout << "Invalid move!" << endl;
            return 0;
        }
    }
    char checkWinner() {
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                return board[i][i] != ' ' ? board[i][i] : ' ';
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            return board[1][1] != ' ' ? board[1][1] : ' ';
        }

        return ' ';
    }

};

int main() {
    TicTacToe game;

    // Example moves
    int flag = 1;
    int r, c;
    int cnt = 0;
    while(1){
        cout<<"\nEnter row & column for player "<<(flag?'X':'O')<<": ";
        cin >> r >> c;

        if (game.makeMove(r, c, flag?'X':'O')) flag =! flag;
        char win = game.checkWinner();
        game.displayBoard();
        if (win != ' '){
            cout << win <<" won the match" << endl;
            break;
        }
        cnt++;
        if (cnt == 9){
            cout << "Game ended" << endl;
            break;
        }
    }
    // Display the board

    return 0;
}
