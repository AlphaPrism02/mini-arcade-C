#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include </workspaces/mini-arcade-C/tictactoe.c>

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

int madlibs(){
    char adj1[50],adj2[50],adj3[50],noun[50],verb[50];

    printf("enter adjective: ");
    fgets(adj1,50,stdin);
    
    printf("enter noun: ");
    fgets(noun,50,stdin);

    printf("enter adjective: ");
    fgets(adj2,50,stdin);

    printf("enter verb: ");
    fgets(verb,50,stdin);

    printf("enter adjective: ");
    fgets(adj3,50,stdin);

    //removing newlines
    adj1[strcspn(adj1, "\n")] = '\0';
    noun[strcspn(noun, "\n")] = '\0';
    adj2[strcspn(adj2, "\n")] = '\0';
    verb[strcspn(verb, "\n")] = '\0';
    adj3[strcspn(adj3, "\n")] = '\0';


    printf("today i went to a %s zoo\n",adj1);
    printf("in an exhibit, i saw %s\n",noun);
    printf("%s was %s and %s\n",noun,adj2,verb);
    printf("i was %s\n",adj3);

    return 0;
}