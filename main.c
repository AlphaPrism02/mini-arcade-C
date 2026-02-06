#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include </workspaces/mini-arcade-C/tictactoe.c>
#include </workspaces/mini-arcade-C/rock_paper_scissors.c>
int number_guessing();
void main()
{
    //add menu to start different games
    char name[50];
    int choice;
    printf("ENTER NAME: \n");
    fgets(name, sizeof(name), stdin);  
    printf(".......MINI ARCADE GAMES.......\n");
    Sleep(1000);
    printf("HEYYYY %s \n", name);
    Sleep(800);

    printf("Feeling brave enough for TIC TAC TOE?\n");
    printf("1 - Bring it on \n");
    printf("2 - I'll warm up with mini games \n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        start_tictactoe();
        break;
        case 2:
        startrockpaperscissors();
        case 3:
        number_guessing();
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

