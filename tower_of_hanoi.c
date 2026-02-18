#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

int countMinMoves(int n);
int choseDiskAmt();
void diskOprInput(int *diskno,char *from_where,char *to_where,int NO_OF_DISKS);
bool moveDisk(int diskno,char from[][20],char to[][20],int NO_OF_DISKS,char from_where,char to_where);
bool isInvalidInput(int diskno,char from_where,char to_where,int NO_OF_DISKS);
int topRingIndex(char rings[][20],int NO_OF_DISKS);
int emptySpotIndex(char spot[][20],int NO_OF_DISKS);
void displayTOH(char start[][20],char aux[][20],char dest[][20],int NO_OF_DISKS);
bool ringExistsHere(char from[][20],int diskno,int top_ring);
bool bigRingOnSmall(char from[][20],int top_ring,char to[][20],int empty_spot,int NO_OF_DISKS);

void start_toh()
{
    const char DISKS[6][20]={"      *1*","     **2**","    ***3***","   ****4****","  *****5*****"," ******6******"};

    printf("\033[2J\033[H"); //to clear the screen
    printf("You have to move the rings such that they move to the destination in the same order.\n");
    printf("Rules:\n1. You can only move one ring at a time\n2. You cannot put a larger ring on a smaller ring\n");
    sleep(1.5);

    const int NO_OF_DISKS=choseDiskAmt();
    const int MINIMUM_MOVES=countMinMoves(NO_OF_DISKS);

    char startpos[NO_OF_DISKS][20],auxpos[NO_OF_DISKS][20],destpos[NO_OF_DISKS][20];

    for(int i=0;i<NO_OF_DISKS;i++)
    {
        strcpy(startpos[i], DISKS[i]);
        strcpy(auxpos[i],"");
        strcpy(destpos[i],"");
    }
    //printf("_______________      _______________      _______________\n       s                    a                    d\n");
    displayTOH(startpos,auxpos,destpos,NO_OF_DISKS);
    
    int diskno;
    char from_where,to_where;

    int no_of_turns=0;
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
                    break;

            case 'a':
                    switch(to_where)
                    {
                        case 's':
                                disk_moved=moveDisk(diskno,auxpos,startpos,NO_OF_DISKS,from_where,to_where);
                                break;
                        case 'a':
                                printf("disc is already here\n");
                                break;
                        case 'd':
                                disk_moved=moveDisk(diskno,auxpos,destpos,NO_OF_DISKS,from_where,to_where);
                                break;
                    }
                    break;

            case 'd':
                    switch(to_where)
                    {
                        case 's':
                                disk_moved=moveDisk(diskno,destpos,startpos,NO_OF_DISKS,from_where,to_where);
                                break;
                        case 'a':
                                disk_moved=moveDisk(diskno,destpos,auxpos,NO_OF_DISKS,from_where,to_where);
                                break;
                        case 'd':
                                printf("disc is already here\n");
                                break;
                    }
                    break;
        }
        
        if(!disk_moved)
        {continue;}

        no_of_turns++;
        displayTOH(startpos,auxpos,destpos,NO_OF_DISKS);
        
    }

    sleep(1);
    printf("You Win!\nYou completed this level in %d moves\n",no_of_turns);
    printf("The minimum moves required are: %d\n",MINIMUM_MOVES);
}

void displayTOH(char start[][20],char aux[][20],char dest[][20],int NO_OF_DISKS)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<NO_OF_DISKS;j++)
        {
            if(i==0)
            {printf("%s\n",start[j]);}
            else if(i==1)
            {printf("%s\n",aux[j]);}
            else
            {printf("%s\n",dest[j]);}
        }
        if(i==0)
        {printf("_______________\n       s\n");}
        else if(i==1)
        {printf("_______________\n       a\n");}
        else
        {printf("_______________\n       d\n");}
    }
}

int countMinMoves(int n)
{
    return (1 << n) - 1;   // 2^n - 1 this is called bit shifting (this is from chatgpt but makes sense to use)

    /*
    if (n == 0)
    {
        return 0;
    }

    return 2* countMinMoves(n - 1) +1;
    */

    //This was my original idea (recursive)
    
}

int choseDiskAmt()
{
    int n;

    do
    {
        sleep(2);
        printf("Enter the number of disks you want to play with\nPick a number between 3-6\n");
        scanf("%d",&n);

        if(n<3)
        {
            printf("the value is too less\n");
        }
        else if(n>6)
        {
            printf("the value is too big\n");
        }

    } while (n<3 || n>6);
    
    return n;
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

    scanf(" %c %c",from_where,to_where);

    if(isInvalidInput(*diskno,*from_where,*to_where,NO_OF_DISKS))
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

    return false;
}

bool moveDisk(int diskno,char from[][20],char to[][20],int NO_OF_DISKS,char from_where,char to_where)
{
    printf("moving disc %d from %c to %c\n",diskno,from_where,to_where);

    int top_ring=topRingIndex(from,NO_OF_DISKS);

    if(top_ring==-1)
    {
        printf("this place is empty\n");
        return false;
    }

    if(!ringExistsHere(from,diskno,top_ring))
    {
        printf("top ring index dos not match desired ring operation\n");
        return false;
    }

    int empty_spot=emptySpotIndex(to,NO_OF_DISKS);

    if(bigRingOnSmall(from,top_ring,to,empty_spot,NO_OF_DISKS))
    {
        printf("Cant put a bigger ring on top of a smaller ring\n");
        return false;
    }
    
    strcpy(to[empty_spot],from[top_ring]); //copying top ring value to empty spot value
    strcpy(from[top_ring],""); //resetting top ring value to ""

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

bool ringExistsHere(char from[][20],int diskno,int top_ring)
{
    char diskchar=diskno+'0';

    if(strchr(from[top_ring],diskchar))
    {return true;}

    return false;
}

bool bigRingOnSmall(char from[][20],int top_ring,char to[][20],int empty_spot,int NO_OF_DISKS)
{
    if(empty_spot+1>=NO_OF_DISKS)
    {return false;}

    int ring_from,ring_to;
    
    for(int i=strlen(from[top_ring])-1;i>=0;i--) //checks the str len of string at the top ring index
    {
        if(isdigit(from[top_ring][i]))
        {
            ring_from=(int)from[top_ring][i];
            break;
        }
    }

    for(int i=strlen(to[empty_spot+1])-1;i>=0;i--) //checks str len of string at empty spot+1 (empty spot has null string)
    {
        if(isdigit(to[empty_spot+1][i]))
        {
            ring_to=(int)to[empty_spot+1][i];
            break;
        }
    }
    
    if(ring_from>ring_to)
    {return true;}

    return false;
}