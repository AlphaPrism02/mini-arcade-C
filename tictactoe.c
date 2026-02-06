#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void display();

void start_tictactoe()
{
    //int gridvals[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    printf("Tic Tac Toe:\nOn your turn, enter coordinates of the grid.\nFor Example: 1a for the first square of the first column");

    int no_of_turns=1;
    char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    display(grid);
    
    int row_ind;
    char col_ind;
    bool player_win;
    while(no_of_turns<9)
    {
        if(no_of_turns%2!=0)
        {
            printf("Your Turn:");
            scanf("%d%c",&row_ind,&col_ind);

            if(!correct_input(row_ind,col_ind))
            {
                printf("invalid values");
                continue;
            }

            

            if(not_occupied(row_ind,col_ind))
            {
                
            }
        }
    }
    
}

void display(char grid[3][3])
{
    printf("\033[2J\033[H"); //to clear the screen if any grid is already present

    printf("   a   b   c\n");

    for(int i=0;i<3;i++)
    {
        printf("%d: %c | %c | %c\n",i+1,grid[i][0],grid[i][1],grid[i][2]);
        if(i!=2){printf("----------------\n");}
    }
}
