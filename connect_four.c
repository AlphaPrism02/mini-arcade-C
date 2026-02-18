#include <stdio.h>

#define ROWS 6
#define COLS 7

int start_connect_four() {
    char board[ROWS][COLS];
    int i, j, col, turn = 0;
    char player;

    // Initialize board
    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            board[i][j] = '.';

    while(1) {

        // Print board
        printf("\n");
        for(i = 0; i < ROWS; i++) {
            for(j = 0; j < COLS; j++)
                printf("%c ", board[i][j]);
            printf("\n");
        }
        printf("1 2 3 4 5 6 7\n");

        // Select player
        player = (turn % 2 == 0) ? 'X' : 'O';

        printf("Player %c choose column (1-7): ", player);
        scanf("%d", &col);
        col--;

        if(col < 0 || col >= COLS) {
            printf("Invalid move!\n");
            continue;
        }

        // Drop piece
        for(i = ROWS-1; i >= 0; i--) {
            if(board[i][col] == '.') {
                board[i][col] = player;
                break;
            }
        }

        if(i < 0) {
            printf("Column full!\n");
            continue;
        }

        turn++;

        // ---------- CHECK WIN ----------
        int win = 0;

        // Horizontal
        for(i = 0; i < ROWS; i++)
            for(j = 0; j < COLS-3; j++)
                if(board[i][j] == player &&
                   board[i][j+1] == player &&
                   board[i][j+2] == player &&
                   board[i][j+3] == player)
                    win = 1;

        // Vertical
        for(i = 0; i < ROWS-3; i++)
            for(j = 0; j < COLS; j++)
                if(board[i][j] == player &&
                   board[i+1][j] == player &&
                   board[i+2][j] == player &&
                   board[i+3][j] == player)
                    win = 1;

        // Diagonal \
        for(i = 0; i < ROWS-3; i++)
            for(j = 0; j < COLS-3; j++)
                if(board[i][j] == player &&
                   board[i+1][j+1] == player &&
                   board[i+2][j+2] == player &&
                   board[i+3][j+3] == player)
                    win = 1;

        // Diagonal /
        for(i = 3; i < ROWS; i++)
            for(j = 0; j < COLS-3; j++)
                if(board[i][j] == player &&
                   board[i-1][j+1] == player &&
                   board[i-2][j+2] == player &&
                   board[i-3][j+3] == player)
                    win = 1;

        if(win) {
            printf("\nPlayer %c wins!\n", player);
            break;
        }

        // Draw
        if(turn == ROWS * COLS) {
            printf("Game draw!\n");
            break;
        }
    }

    return 0;
}
