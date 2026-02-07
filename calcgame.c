#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void start_calcgame() {
    int playerLife = 3, compLife = 3;
    int a, b, ans, userAns;
    char op;
    time_t start, end;  //declaring time variables to get startn and end timings
    double timeTaken;

    printf("\n..... CALCULATOR BATTLE .....\n");
    printf("U GOT 4 SECONDSS TO ANSWER....\n");
    sleep(1.5);
    printf("READYYY?????\n");
    sleep(1);
    printf("START..\n"); 
    sleep(1);

    while(playerLife > 0 && compLife > 0) {

        a = rand() % 10 + 1;
        b = rand() % 10 + 1;

        switch(rand() % 4) {
            case 0: op = '+'; ans = a + b; break;
            case 1: op = '-'; ans = a - b; break;
            case 2: op = '*'; ans = a * b; break;
            case 3: op = '/'; ans = a / b; break; // integer division
        }

        printf("\nLives : You: %d | Computer: %d\n", playerLife, compLife);
        printf("Solve: %d %c %d = ?\n", a, op, b);
        printf("You have 4 seconds!\n");

        time(&start);          // start timer
        scanf("%d", &userAns); // user input
        time(&end);            // end timer

        timeTaken = difftime(end, start);

        if(timeTaken > 4) {
            printf("TIME UP! You took %.1f seconds\n", timeTaken);
            printf("You lose 1 life \n");
            playerLife--;
        }
        else if(userAns == ans) {
            printf("Correct within time! \n");
            printf("Computer loses 1 life\n");
            compLife--;
        }
        else {
            printf("Wrong answer! Correct was %d\n", ans);
            printf("You lose 1 life \n");
            playerLife--;
        }
    }

    if(playerLife == 0)
        printf("\n COMPUTER WINS!\n");
    else
        printf("\n YOU WIN!\n");
}
