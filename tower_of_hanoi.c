#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int countMinimumMoves(int n, char source, char auxiliary, char destination,int min_moves);
int choseDiskAmt();

void start_toh()
{
    const char DISKS[6][20]={"     **","    ****","   ******","  ********"," **********","************"};

    const int NO_OF_DISKS=choseDiskAmt();

    char startpos[NO_OF_DISKS][20],auxpos[NO_OF_DISKS][20],destpos[NO_OF_DISKS][20];

    for(int i=0;i<NO_OF_DISKS;i++)
    {
        strcpy(startpos[i], DISKS[i]);
        printf("%s\n",startpos[i]);
    }
}

int countMinimumMoves(int n, char source, char auxiliary, char destination,int min_moves)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return min_moves+1;
    }

    countMinimumMoves(n - 1, source, destination, auxiliary,min_moves+1);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    countMinimumMoves(n - 1, auxiliary, source, destination,min_moves+1);
}

int choseDiskAmt()
{
    int n;
    printf("Enter the number of disks you want to play with\nPick a number between 3-6\n");
    scanf("%d",&n);

    if(n<3)
    {
        printf("the value is too less\n");
        return choseDiskAmt();
    }
    else if(n>6)
    {
        printf("the value is too big\n");
        return choseDiskAmt();
    }
    else
    {return n;}
}