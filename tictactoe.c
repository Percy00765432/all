#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Game board size
#define BOARD_SIZE 3

// Player and Computer symbols
#define PLAYER 'X'
#define COMPUTER 'O'
#define EMPTY ' '

// Function prototypes
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void display_board(char board[BOARD_SIZE][BOARD_SIZE]);
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]);
int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player);
void player_move(char board[BOARD_SIZE][BOARD_SIZE]);
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]);
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col);

// Difficulty levels for computer AI
typedef enum {
    EASY,
    MEDIUM,
    HARD
} Difficulty;

// Game statistics
typedef struct {
    int player_wins;
    int computer_wins;
    int draws;
} GameStats;

// Main game function
void play_game(Difficulty difficulty) {
    char board[BOARD_SIZE][BOARD_SIZE];
    GameStats stats = {0, 0, 0};
    char play_again;

    do {
        // Initialize board
        initialize_board(board);
        int current_player = 1;  // 1 for player, 0 for computer
        int game_over = 0;

        while (!game_over) {
            display_board(board);

            if (current_player) {
                // Player's turn
                player_move(board);
                
                if (check_winner(board, PLAYER)) {
                    printf("Congratulations! You won!\n");
                    stats.player_wins++;
                    game_over = 1;
                }
            } else {
                // Computer's turn
                computer_move(board);
                
                if (check_winner(board, COMPUTER)) {
                    printf("Computer won! Better luck next time.\n");
                    stats.computer_wins++;
                    game_over = 1;
                }
            }

            // Check for draw
            if (is_board_full(board) && !game_over) {
                printf("It's a draw!\n");
                stats.draws++;
                game_over = 1;
            }

            // Switch players
            current_player = !current_player;
        }

        // Display final board
        display_board(board);

        // Show game statistics
        printf("\n--- Game Statistics ---\n");
        printf("Player Wins: %d\n", stats.player_wins);
        printf("Computer Wins: %d\n", stats.computer_wins);
        printf("Draws: %d\n", stats.draws);

        // Ask to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');
}

// Initialize the game board with empty spaces
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

// Display the current game board
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) 
            printf("---+---+---\n");
    }
    printf("\n");
}

// Check if the board is full
int is_board_full(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                return 0;
            }
        }
    }
    return 1;
}

// Check for a winner
int check_winner(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && 
            board[i][1] == player && 
            board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && 
            board[1][j] == player && 
            board[2][j] == player) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && 
         board[1][1] == player && 
         board[2][2] == player) ||
        (board[0][2] == player && 
         board[1][1] == player && 
         board[2][0] == player)) {
        return 1;
    }

    return 0;
}

// Validate move
int is_valid_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    return (row >= 0 && row < BOARD_SIZE && 
            col >= 0 && col < BOARD_SIZE && 
            board[row][col] == EMPTY);
}

// Player's move
void player_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    int row, col;
    do {
        printf("Enter your move (row and column, 0-2): ");
        scanf("%d %d", &row, &col);
    } while (!is_valid_move(board, row, col));

    board[row][col] = PLAYER;
}

// Computer's move with basic strategy
void computer_move(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Try to win
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                if (check_winner(board, COMPUTER)) {
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // Block player's winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = PLAYER;
                if (check_winner(board, PLAYER)) {
                    board[i][j] = COMPUTER;
                    return;
                }
                board[i][j] = EMPTY;
            }
        }
    }

    // Random move
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (!is_valid_move(board, row, col));

    board[row][col] = COMPUTER;
}

// Main function
int main() {
    int difficulty_choice;
    printf("Select Difficulty:\n");
    printf("1. Easy\n2. Medium\n3. Hard\n");
    printf("Enter your choice: ");
    scanf("%d", &difficulty_choice);

    switch(difficulty_choice) {
        case 1:
            play_game(EASY);
            break;
        case 2:
            play_game(MEDIUM);
            break;
        case 3:
            play_game(HARD);
            break;
        default:
            printf("Invalid choice. Defaulting to Easy.\n");
            play_game(EASY);
    }

    return 0;
}