#include <iostream>
using namespace std;

// Function prototypes
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char currentPlayer, int row, int col);
bool checkWin(const char board[3][3], char currentPlayer);
bool checkDraw(const char board[3][3]);
char switchPlayer(char currentPlayer);
char getPlayerChoice();

int main() {
    char board[3][3] = { {'-', '-', '-'},
                         {'-', '-', '-'},
                         {'-', '-', '-'} };
    char currentPlayer = getPlayerChoice();
    bool gameOver = false;

    do {
        displayBoard(board);

        // Get player's move (row)
        int row;
        cout << "Player " << currentPlayer << ", enter row (1-3): ";
        cin >> row;

        // Validate row input
        if (row < 1 || row > 3) {
            cout << "Invalid row! Please enter a number between 1 and 3.\n";
            continue;
        }

        // Get player's move (column)
        int col;
        cout << "Player " << currentPlayer << ", enter column (1-3): ";
        cin >> col;

        // Validate column input
        if (col < 1 || col > 3) {
            cout << "Invalid column! Please enter a number between 1 and 3.\n";
            continue;
        }

        // Check if the move is valid
        if (board[row - 1][col - 1] != '-') {
            cout << "That cell is already occupied! Please choose another.\n";
            continue;
        }

        // Make the move
        board[row - 1][col - 1] = currentPlayer;

        // Check for win
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // Switch players
        currentPlayer = switchPlayer(currentPlayer);

    } while (!gameOver);

    cout << "Thanks for playing Tic-Tac-Toe!\n";

    return 0;
}

// Display the current state of the board
void displayBoard(const char board[3][3]) {
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Make a move on the board
bool makeMove(char board[3][3], char currentPlayer, int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false;
    }
}

// Check if the current player has won
bool checkWin(const char board[3][3], char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }

    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check if the game is a draw
bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == '-')
                return false;
        }
    }
    return true;
}

// Switch players between 'X' and 'O'
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

// Prompt user to choose 'X' or 'O'
char getPlayerChoice() {
    char choice;
    cout << "Enter your choice ('X' or 'O'): ";
    cin >> choice;

    while (choice != 'X' && choice != 'O') {
        cout << "Invalid choice! Please enter 'X' or 'O': ";
        cin >> choice;
    }

    return choice;
}
