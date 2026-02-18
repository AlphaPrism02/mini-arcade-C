#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define MINES 5

void initializeGrid(char grid[SIZE][SIZE], char visible[SIZE][SIZE]);
void displayGrid(char visible[SIZE][SIZE], int playerX, int playerY);

int start_minesweeper() {
    char grid[SIZE][SIZE];
    char visible[SIZE][SIZE];
    int playerX = 0, playerY = 0;
    char move;

    srand(time(NULL));
    initializeGrid(grid, visible);

    printf(".....MINESWEEPER.....\n");
    printf("Reach the Goal (G) without hitting a MINE!\n");
    printf("Use W (up), A (left), S (down), D (right)\n");

    while(1) {
        displayGrid(visible, playerX, playerY);

        printf("\nEnter move: ");
        scanf(" %c", &move);

        int newX = playerX;
        int newY = playerY;

        if(move == 'W' || move == 'w') newX--;
        else if(move == 'S' || move == 's') newX++;
        else if(move == 'A' || move == 'a') newY--;
        else if(move == 'D' || move == 'd') newY++;
        else {
            printf("Invalid input!\n");
            continue;
        }

        // Check for boundary
        if(newX < 0 || newX >= SIZE || newY < 0 || newY >= SIZE) {
            printf("You hit the boundary! Try again.\n");
            continue;
        }

        // Check for mine
        if(grid[newX][newY] == 'M') {
            printf("\nBOOM! You stepped on a mine!\n");
            printf("GAME OVER\n");
            break;
        }

        // Moving the player
        playerX = newX;
        playerY = newY;
        visible[playerX][playerY] = 'O';

        // Check victory
        if(playerX == SIZE-1 && playerY == SIZE-1) {
            displayGrid(visible, playerX, playerY);
            printf("\nGREAT JOB!!! YOU SURVIVED THE MINEFIELD!\n");
            break;
        }
    }

    return 0;
}

// 🔹 Function Definitions Below main

void initializeGrid(char grid[SIZE][SIZE], char visible[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
            visible[i][j] = '?';
        }
    }

    int count = 0;
    while(count < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if(grid[x][y] == '.' && !(x == 0 && y == 0) &&
           !(x == SIZE-1 && y == SIZE-1)) {
            grid[x][y] = 'M';
            count++;
        }
    }

    visible[SIZE-1][SIZE-1] = 'G';
}

void displayGrid(char visible[SIZE][SIZE], int playerX, int playerY) {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(i == playerX && j == playerY)
                printf("P ");
            else
                printf("%c ", visible[i][j]);
        }
        printf("\n");
    }
}
