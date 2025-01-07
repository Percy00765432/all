#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global variables
char board[3][3];
const char PLAYER = 'X';
const char BOT = 'O';
const char EMPTY = ' ';

// Function prototypes
void initializeBoard();
void printBoard();
bool isMovesLeft();
bool isValidMove(int row, int col);
void playerMove();
void botMove();
bool checkWin(char player);
int minimax(bool isMaximizing);

// Initialize the board with empty spaces
void initializeBoard() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            board[i][j] = EMPTY;
}

// Print the current state of the board
void printBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) printf("\n---+---+---\n");
    }
    printf("\n");
}

// Check if there are moves remaining
bool isMovesLeft() {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == EMPTY)
                return true;
    return false;
}

// Validate if a move is legal
bool isValidMove(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2)
        return false;
    return board[row][col] == EMPTY;
}

// Handle player's move
void playerMove() {
    int row, col;
    do {
        printf("\nEnter your move (row[1-3] column[1-3]): ");
        scanf("%d %d", &row, &col);
        row--; col--; // Convert to 0-based indexing
    } while(!isValidMove(row, col));
    
    board[row][col] = PLAYER;
}

// Check if current player has won
bool checkWin(char player) {
    // Check rows
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    
    // Check columns
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    
    // Check diagonals
    if(board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if(board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
        
    return false;
}

// Minimax algorithm for bot's decision making
int minimax(bool isMaximizing) {
    if(checkWin(BOT)) return 1;
    if(checkWin(PLAYER)) return -1;
    if(!isMovesLeft()) return 0;
    
    if(isMaximizing) {
        int bestScore = -1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == EMPTY) {
                    board[i][j] = BOT;
                    bestScore = max(bestScore, minimax(false));
                    board[i][j] = EMPTY;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == EMPTY) {
                    board[i][j] = PLAYER;
                    bestScore = min(bestScore, minimax(true));
                    board[i][j] = EMPTY;
                }
            }
        }
        return bestScore;
    }
}

// Handle bot's move using minimax algorithm
void botMove() {
    int bestScore = -1000;
    int bestMoveRow = -1;
    int bestMoveCol = -1;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == EMPTY) {
                board[i][j] = BOT;
                int score = minimax(false);
                board[i][j] = EMPTY;
                
                if(score > bestScore) {
                    bestScore = score;
                    bestMoveRow = i;
                    bestMoveCol = j;
                }
            }
        }
    }
    
    board[bestMoveRow][bestMoveCol] = BOT;
    printf("\nBot placed 'O' at position: %d %d\n", bestMoveRow + 1, bestMoveCol + 1);
}

// Helper function for minimax
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function for minimax
int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are X, bot is O\n");
    
    initializeBoard();
    printBoard();
    
    while(true) {
        playerMove();
        printBoard();
        
        if(checkWin(PLAYER)) {
            printf("\nCongratulations! You win!\n");
            break;
        }
        
        if(!isMovesLeft()) {
            printf("\nGame Draw!\n");
            break;
        }
        
        printf("\nBot's turn...\n");
        botMove();
        printBoard();
        
        if(checkWin(BOT)) {
            printf("\nBot wins! Better luck next time!\n");
            break;
        }
        
        if(!isMovesLeft()) {
            printf("\nGame Draw!\n");
            break;
        }
    }
    
    return 0;
}