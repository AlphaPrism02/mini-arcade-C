#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include </workspaces/mini-arcade-C/tictactoe.c>
#include </workspaces/mini-arcade-C/rock_paper_scissors.c>
#include </workspaces/mini-arcade-C/calcgame.c>
#include </workspaces/mini-arcade-C/hangman.c>
#include </workspaces/mini-arcade-C/tower_of_hanoi.c>
#include </workspaces/mini-arcade-C/memory-game.c>
#include </workspaces/mini-arcade-C/snake.c>
#include </workspaces/mini-arcade-C/jumble.c>
#include </workspaces/mini-arcade-C/minesweeper.c>
#include </workspaces/mini-arcade-C/connect_four.c>
#include </workspaces/mini-arcade-C/sudoku.c>

void main()
{
    //add menu to start different games
    int choice;  
    printf(".......MINI ARCADE GAMES.......\n");
    sleep(1.5);

    printf("What game would you like to play?\n");
    printf("1 - Tower of Hanoi \n2 - Snake \n3 - Tic-Tac-Toe\n4 - Minesweeper\n5 - Math Quiz\n6 - Number Memory\n7 - Rock Paper Scissors\n8 - Hangman\n9 - Word Jumble\n10- Connect Four (Multiplayer)\n11 - Sudoku\n0 - exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        start_toh();
        break;

        case 2:
        start_snake();
        break;

        case 3:
        start_tictactoe();
        break;

        case 4:
        start_minesweeper();
        break;

        case 5:
        start_calcgame();
        break;

        case 6:
        start_numMemory();
        break;

        case 7:
        start_rockpaperscissors();
        break;

        case 8:
        start_hangman();
        break;

        case 9:
        start_jumble();
        break;

        case 10:
        start_connect_four();
        break;
        
        case 11:
        start_sudoku();
        break;

        case 0:
        printf("Successfully Quit Game");
        break;

        default:
        printf("Invalid Input");
    }
    
}
