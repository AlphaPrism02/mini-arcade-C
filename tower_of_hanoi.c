#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int countMinimumMoves(int n, int min_moves);
int choseDiskAmt();
void diskOprInput(int *diskno,char *from_where,char *to_where,int NO_OF_DISKS);
bool moveDisk(int diskno,char from[][20],char to[][20],int NO_OF_DISKS,char from_where,char to_where);
bool isInvalidInput(int diskno,char from_where,char to_where,int NO_OF_DISKS);
int topRingIndex(char rings[][20],int NO_OF_DISKS);
int emptySpotIndex(char spot[][20],int NO_OF_DISKS);
void displayTOH(char start[][20],char aux[][20],char dest[][20],int NO_OF_DISKS);

void start_toh()
{
    const char DISKS[6][20]={"      *1*","     **2**","    ***3***","   ****4****","  *****5*****"," ******6******"};

    printf("You have to move the rings such that they move to the destination in the same order.\n");
    printf("Rules:\n1. You can only move one ring at a time\n2. You cannot put a larger ring on a smaller ring\n");
    sleep(1.5);

    const int NO_OF_DISKS=choseDiskAmt();
    const int MINIMUM_MOVES=countMinimumMoves(NO_OF_DISKS, 0);

    char startpos[NO_OF_DISKS][20],auxpos[NO_OF_DISKS][20],destpos[NO_OF_DISKS][20];

    for(int i=0;i<NO_OF_DISKS;i++)
    {
        strcpy(startpos[i], DISKS[i]);
        strcpy(auxpos[i],"");
        strcpy(destpos[i],"");
        printf("%s\n",startpos[i]);
    }
    printf("_______________      _______________      _______________\n       s                    a                    d\n");
    sleep(3);
    
    int diskno;
    char from_where,to_where;

    int no_of_turns=1;
    while(strcmp(DISKS[0],destpos[0]) != 0)
    {
        diskOprInput(&diskno,&from_where,&to_where,NO_OF_DISKS);

        bool disk_moved;
        switch(from_where)
        {
            case 's':
                    switch(to_where)
                    {
                        case 's':
                                printf("disc is already here\n");
                                break;
                        case 'a':
                                disk_moved=moveDisk(diskno,startpos,auxpos,NO_OF_DISKS,from_where,to_where);
                                break;
                        case 'd':
                                disk_moved=moveDisk(diskno,startpos,destpos,NO_OF_DISKS,from_where,to_where);
                                break;
                    }

            
        }
        
        if(!disk_moved)
        {continue;}

        displayTOH(startpos,auxpos,destpos,NO_OF_DISKS);
        
    }


}

void displayTOH(char start[][20],char aux[][20],char dest[][20],int NO_OF_DISKS)
{
    for(int i=0;i<NO_OF_DISKS;i++)
    {
        printf("%s      %s      %s\n",start[i],aux[i],dest[i]);
    }

    printf("_______________      _______________      _______________\n       s                    a                    d\n");
}

int countMinimumMoves(int n, int min_moves)
{
    if (n == 1)
    {
        //printf("Move disk 1 from %c to %c\n", source, destination);
        return min_moves+1;
    }

    countMinimumMoves(n - 1, min_moves+1);
    //printf("Move disk %d from %c to %c\n", n, source, destination);
    countMinimumMoves(n - 1, min_moves+1);
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

void diskOprInput(int *diskno,char *from_where,char *to_where,int NO_OF_DISKS)
{
    sleep(1);
    printf("\nEnter the disk operation u want to perform\nFor Example:\nTo move disk 1 from start to auxillary, enter: 1 s a\n");
    printf("Enter 0 to quit\n");
    scanf("%d",diskno);

    if((*diskno)==0)
    {
        printf("Quit Game\n");
        exit(0);
    }

    scanf("%c %c",&from_where,&to_where);

    if(isInvalidInput(diskno,from_where,to_where,NO_OF_DISKS))
    {
        diskOprInput(diskno,from_where,to_where,NO_OF_DISKS);
    }
    
}

bool isInvalidInput(int diskno,char from_where,char to_where,int NO_OF_DISKS)
{
    if(diskno>NO_OF_DISKS)
    {
        printf("Invalid disk no.\n");
        return true;
    }

    if( (from_where!='s' && from_where!='S') &&
        (from_where!='a' && from_where!='A') &&
        (from_where!='d' && from_where!='D')  )
    {
        printf("Invalid position character\n");
        return true;
    }

    if( (to_where!='s' && to_where!='S') &&
        (to_where!='a' && to_where!='A') &&
        (to_where!='d' && to_where!='D')  )
    {
        printf("Invalid position character\n");
        return true;
    }
}

bool moveDisk(int diskno,char from[][20],char to[][20],int NO_OF_DISKS,char from_where,char to_where)
{
    printf("moving disc %d from %c to %c\n",diskno,from_where,to_where);

    int top_ring=topRingIndex(from,NO_OF_DISKS);

    if(top_ring==-1)
    {
        printf("this place is empty");
        return false;
    }

    int empty_spot=emptySpotIndex(to,NO_OF_DISKS);
    
    strcpy(from[top_ring],to[empty_spot]); //copying top ring value to empty spot value
    strcpy("",from[top_ring]); //resetting top ring value to ""

    return true;
}

int topRingIndex(char rings[][20],int NO_OF_DISKS)
{
    for(int i=0;i<NO_OF_DISKS;i++)
    {
        if(strcmp(rings[i],"") != 0)
        {
            return i;
        }
    }
    return -1;
}

int emptySpotIndex(char spot[][20],int NO_OF_DISKS)
{
    for(int i=0;i<NO_OF_DISKS;i++)
    {
        if(strcmp(spot[i],"") != 0)
        {
            return --i;
        }
    }
    return --NO_OF_DISKS;
}