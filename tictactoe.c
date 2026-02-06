#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void display(char grid[3][3]);
bool invalid_input(int row_ind,char col,int *col_ind);
bool occupied(char grid_val);

void start_tictactoe()
{
    //int gridvals[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printf("Tic Tac Toe:\nOn your turn, enter coordinates of the grid.\nFor Example: 1a for the first square of the first column");

    int no_of_turns=1;
    char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    display(grid);
    
    int row_ind,col_ind;
    char col;
    bool player_win;
    while(no_of_turns<9)
    {
        if(no_of_turns%2!=0)
        {
            printf("Your Turn:");
            scanf("%d%c",&row_ind,&col);

            if(invalid_input(row_ind,col,&col_ind) || occupied(grid[row_ind][col_ind]))
            {
                continue; //allows the user to reenter the values without going thru the rest of the code
            }

            grid[row_ind][col_ind]='X'; //sets the player mark;

        }
        no_of_turns++;
    }
    
}

void display(char grid[3][3])
{
    //printf("\033[2J\033[H"); //to clear the screen if any grid is already present

    printf("   a   b   c\n");

    for(int i=0;i<3;i++)
    {
        printf("%d: %c | %c | %c\n",i+1,grid[i][0],grid[i][1],grid[i][2]);
        if(i!=2){printf("----------------\n");}
    }
}

bool invalid_input(int row_ind,char col,int *col_ind)
{
    if(row_ind>2 || row_ind<0)
    {
        printf("invalid values");
        return true;
    }

    if(col=='a' || col=='A')
    {
        *col_ind=0;
        return false;
    }
    else if(col=='b' || col=='B')
    {
        *col_ind=1;
        return false;
    }
    else if(col=='c' || col=='C')
    {
        *col_ind=2;
        return false;
    }
    else
    {
        printf("invalid values");
        return true;
    }
}

bool occupied(char grid_val)
{
    if(grid_val==' ')
    {return false;}

    if(grid_val=='X')
    {
        printf("You already played there");
        return true;
    }
    else
    {
        printf("The computer has played there");
        return true;
    }
}
