#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

// Initialize board
void initBoard() {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            board[i][j] = '.';
}

// Print board
void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("1 2 3 4 5 6 7\n");
}

// Drop piece
int dropPiece(int col, char player) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == '.') {
            board[i][col] = player;
            return 1;
        }
    }
    return 0;
}

// Check win
int checkWin(char p) {

    // Horizontal
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS - 3; j++)
            if (board[i][j]==p && board[i][j+1]==p &&
                board[i][j+2]==p && board[i][j+3]==p)
                return 1;

    // Vertical
    for (int i = 0; i < ROWS - 3; i++)
        for (int j = 0; j < COLS; j++)
            if (board[i][j]==p && board[i+1][j]==p &&
                board[i+2][j]==p && board[i+3][j]==p)
                return 1;

    // Diagonal \
    for (int i = 0; i < ROWS - 3; i++)
        for (int j = 0; j < COLS - 3; j++)
            if (board[i][j]==p && board[i+1][j+1]==p &&
                board[i+2][j+2]==p && board[i+3][j+3]==p)
                return 1;

    // Diagonal /
    for (int i = 3; i < ROWS; i++)
        for (int j = 0; j < COLS - 3; j++)
            if (board[i][j]==p && board[i-1][j+1]==p &&
                board[i-2][j+2]==p && board[i-3][j+3]==p)
                return 1;

    return 0;
}

// Computer move (random column)
int computerMove() {
    int col;
    do {
        col = rand() % COLS;
    } while (!dropPiece(col, 'O'));
    return col;
}

int main() {
    int col, turn = 0;

    srand(time(0));
    initBoard();

    while (1) {
        printBoard();

        if (turn % 2 == 0) {
            // Player move
            printf("Your turn (X). Choose column (1-7): ");
            scanf("%d", &col);
            col--;

            if (col < 0 || col >= COLS || !dropPiece(col, 'X')) {
                printf("Invalid move!\n");
                continue;
            }

            if (checkWin('X')) {
                printBoard();
                printf("You win!\n");
                break;
            }

        } else {
            // Computer move
            int c = computerMove();
            printf("Computer chose column %d\n", c + 1);

            if (checkWin('O')) {
                printBoard();
                printf("Computer wins!\n");
                break;
            }
        }

        turn++;

        if (turn == ROWS * COLS) {
            printBoard();
            printf("Game draw!\n");
            break;
        }
    }

    return 0;
}
