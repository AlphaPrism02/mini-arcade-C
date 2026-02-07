#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include </workspaces/mini-arcade-C/tictactoe.c>
#include </workspaces/mini-arcade-C/rock_paper_scissors.c>
#include </workspaces/mini-arcade-C/calcgame.c>
#include </workspaces/mini-arcade-C/hangman.c>



int number_guessing();
void main()
{
    //add menu to start different games
    char name[50];
    int choice;
    printf("ENTER NAME: \n");
    fgets(name, sizeof(name), stdin);  
    printf(".......MINI ARCADE GAMES.......\n");
    sleep(1.5);
    printf("HEYYYY %s \n", name);
    sleep(1);

    printf("What game would you like to play?\n");
    printf("1 - Tic-Tac-Toe \n2 - Rock Paper Scissors \n3- Math Quiz\n4- Hangman\n");
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
    }
    
}

int number_guessing(){
    srand(time(NULL));
    int guess,tries=0;
    int min=1;
    int max=100;
    int ans=(rand()%(max-min+1))+min;
    do{
        printf("GUESS A NUMBER BETWEEN 0 - 100\n");
        scanf("%d",&guess);
        tries++;
    }while(guess!=ans);
    printf("THE ANSWER IS %d\n",ans);
    printf("THE TOOK YOU %d TIMES\n",tries);
    return 0;
}

