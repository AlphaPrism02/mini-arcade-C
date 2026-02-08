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


void main()
{
    //add menu to start different games
    char name[50];
    int choice;
    printf("ENTER NAME: \n");
    fgets(name, sizeof(name), stdin);  
    printf(".......MINI ARCADE GAMES.......\n");
    sleep(2);
    
    printf("What game would you like to play?\n");
    printf("1 - Tic-Tac-Toe \n2 - Rock Paper Scissors \n3 - Math Quiz\n4 - Hangman\n5 - Tower Of Hanoi\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        start_tictactoe();
        break;
        case 2:
        startrockpaperscissors();
        case 3:
        start_calcgame();
        case 4:
        start_hangman();
        case 5:
        start_toh();
    }
    
}
