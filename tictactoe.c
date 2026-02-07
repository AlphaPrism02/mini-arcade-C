#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void display(char grid[3][3]);
bool invalid_input(int row_ind,char col,int *col_ind);
bool occupied(char grid_val);
bool bad_rng(char grid_val);
int player_winner(char grid[3][3], int no_of_turns);

void start_tictactoe()
{
    printf("Tic Tac Toe:\nOn your turn, enter coordinates of the grid.\nFor Example: 1a for the first square of the first column\n");

    int no_of_turns=0;
    char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    display(grid);

    int row_ind,col_ind,winner;
    char col;

    while(no_of_turns<9)
    {
        if(no_of_turns%2!=0) //player turn
        {
            sleep(1.5);
            printf("Your Turn:");
            scanf("%d %c",&row_ind,&col);
            row_ind--; //We take 1,2,3 as input so we need to row_ind-1 to correct the inputs

            if(invalid_input(row_ind,col,&col_ind) || occupied(grid[row_ind][col_ind])) 
            {
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); //waits for the input to clear
                continue;
            }  //allows the user to reenter the values without going thru the rest of the code

            grid[row_ind][col_ind]='X'; //sets the player mark;

            no_of_turns++;
        }
        else //computer turn
        {
            srand(time(NULL));   // seed ONCE

            row_ind = rand() % 3;  // 0, 1, or 2
            col_ind = rand() % 3;

            if(bad_rng(grid[row_ind][col_ind]))
            {continue;} //computer retries to pick a grid value

            grid[row_ind][col_ind]='O'; //sets the computer mark;
            sleep(1.5);

            no_of_turns++;
        }

        display(grid);

        winner=player_winner(grid,no_of_turns);
        if(winner==0){continue;}
        else if(winner==1)
        {
            printf("You Win!\n");
            break;
        }
        else if(winner==2)
        {
            printf("You Lose :(\n");
            break;
        }
        else
        {
            printf("Tied -_-\n");
            break;
        }
    }
    //display(grid);
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

bool invalid_input(int row_ind,char col,int *col_ind)
{
    if(row_ind>2 || row_ind<0)
    {
        printf("Invalid values\n");
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
        printf("Invalid values\n");
        return true;
    }
}

bool occupied(char grid_val)
{
    if(grid_val==' ')
    {return false;}

    if(grid_val=='X')
    {
        printf("You already played there\n");
        return true;
    }
    else if(grid_val=='O')
    {
        printf("The computer has played there\n");
        return true;
    }
    else
    {return false;}
}

bool bad_rng(char grid_val)
{
    if(grid_val==' ')
    {return false;}

    if(grid_val=='X')
    {
        return true;
    }
    else if(grid_val=='O')
    {
        return true;
    }
    else
    {return false;}
}

int player_winner(char grid[3][3], int no_of_turns)
{
    if(no_of_turns<4)  {return 0;} //game has to be at least 4 moves long to win
    
    if(no_of_turns==9) {return 3;} //tie

    for(int i=0;i<3;i++)
    {
        if( (grid[i][0]== 'X' && grid[i][1]== 'X' && grid[i][2]== 'X') || 
            (grid[0][i]== 'X' && grid[1][i]== 'X' && grid[2][i]== 'X') ||
            (grid[0][0]== 'X' && grid[1][1]== 'X' && grid[2][2]== 'X') ||
            (grid[2][i]== 'X' && grid[1][i]== 'X' && grid[0][i]== 'X')  )   
            
        {return 1;} //player win


        else if((grid[i][0]== 'O' && grid[i][1]== 'O' && grid[i][2]== 'O') ||
                (grid[0][i]== 'O' && grid[1][i]== 'O' && grid[2][i]== 'O') ||
                (grid[0][0]== 'O' && grid[1][1]== 'O' && grid[2][2]== 'O') ||
                (grid[2][i]== 'O' && grid[1][i]== 'O' && grid[0][i]== 'O')  )
                
        {return 2;} //computer win

    }

    return 0; //continue game;
}