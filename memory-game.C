#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

int start_numMemory()
{
    char number[20]="";
    char guess[20];
    int score=0;
    char choice; 

    srand(time(0));

    do
    {
        score=0;
        number[0]='\0';
        while(1)
        {
            int digit =rand()%10;
            char temp[2];
            sprintf(temp, "%d" ,digit); 
            strcat(number,temp);
            system("clear");
            
            printf("MEMORY NUMBER GAME\n");
            printf("Remember this number\n");
            printf("%s\n",number);

            sleep(5);

            system("clear");
            printf("Enter the number: ");
            scanf("%s",guess);

            if (strcmp(number,guess)==0)
            {
                score++;
            }
            else
            {
                printf("WRONG!\n");
                printf("Your Score : %d\n",score);
                break;
            }
        }
        printf("Play Again ? (y/n)\n");
        scanf(" %c", &choice);
    }
    while(choice=='y' || choice=='Y');
        return 0;
}

