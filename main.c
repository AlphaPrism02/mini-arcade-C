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


void main()
{
    //add menu to start different games
    int choice;  
    printf(".......MINI ARCADE GAMES.......\n");
    sleep(1.5);

    printf("What game would you like to play?\n");
    printf("1 - Tic-Tac-Toe \n2 - Rock Paper Scissors \n3 - Math Quiz\n4 - Hangman\n5 - Tower Of Hanoi\n6 - Number Memory\n7 - Snake\n8 - Word Jumble\n0 - exit");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        start_tictactoe();
        break;
        case 2:
        start_rockpaperscissors();
        break;
        case 3:
        start_calcgame();
        break;
        case 4:
        start_hangman();
        break;
        case 5:
        start_toh();
        break;
        case 6:
        start_numMemory();
        break;
        case 7:
        start_snake();
        break;
        case 8:
        start_jumble();
        break;
        case 0:
        printf("Successfully Quit Game");
        break;
        default:
        printf("Invalid Input");
    }
    
}
