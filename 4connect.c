#include <stdio.h>

#define ROWS 6
#define COLS 7

char board[ROWS][COLS];

// Initialize board
void initBoard() {
    for(int i=0;i<ROWS;i++)
        for(int j=0;j<COLS;j++)
            board[i][j] = '.';
}

// Print board
void printBoard() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("1 2 3 4 5 6 7\n");
}

// Drop piece
int drop(int col, char player) {
    for(int i=ROWS-1;i>=0;i--) {
        if(board[i][col] == '.') {
            board[i][col] = player;
            return 1;
        }
    }
    return 0;
}

// Check horizontal win only (simple version)
int checkWin(char p) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS-3;j++) {
            if(board[i][j]==p &&
               board[i][j+1]==p &&
               board[i][j+2]==p &&
               board[i][j+3]==p)
                return 1;
        }
    }
    return 0;
}

int main() {
    int col, turn = 0;
    char player;

    initBoard();

    while(1) {
        printBoard();

        player = (turn % 2 == 0) ? 'X' : 'O';

        printf("Player %c choose column (1-7): ", player);
        scanf("%d", &col);

        col--; // index adjust

        if(col < 0 || col >= COLS || !drop(col, player)) {
            printf("Invalid move!\n");
            continue;
        }

        if(checkWin(player)) {
            printBoard();
            printf("Player %c wins!\n", player);
            break;
        }

        turn++;

        if(turn == ROWS*COLS) {
            printf("Draw!\n");
            break;
        }
    }

    return 0;
}
