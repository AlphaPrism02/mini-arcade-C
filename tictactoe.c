#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
    int row,col;
}Move;


void displayTicTacToe(char[3][3]);
bool invalidInput(Move*,char);
bool occupied(char);
int winner(char[3][3]);


void start_tictactoe()
{
    printf("Tic Tac Toe:\nOn your turn, enter coordinates of the grid.\nFor Example: 1a for the first square of the first column\n");

    char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    float gridprob[3][3]={{0,0,0},{0,0,0},{0,0,0}};

    displayTicTacToe(grid);

    srand(time(NULL)); // seed ONCE
    int no_of_turns=rand() %2; //Start can be either ai or player

    Move move;
    int win;
    char col;

    while(no_of_turns<9)
    {
        if(no_of_turns%2==0) //player turn
        {
            sleep(1.5);
            printf("Your Turn:");
            scanf("%d %c",&move.row,&col);
            move.row--; //We take 1,2,3 as input so we need to row-1 to correct the inputs

            if(invalidInput(&move,col) || occupied(grid[move.row][move.col])) 
            {
                if(grid[move.row][move.col]=='X') {printf("You already played there\n");}

                else if(grid[move.row][move.col]=='O') {printf("The computer has played there\n");}

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF); //waits for the input to clear
                continue;
            }  //allows the user to re-enter the values without going thru the rest of the code

            grid[move.row][move.col]='X';    //sets the player mark
            gridprob[move.row][move.col]=1;  //sets a probability grid

            no_of_turns++;
        }
        else //computer turn
        {
            move.row = rand() % 3;  // 0, 1, or 2
            move.col = rand() % 3;

            if(occupied(grid[move.row][move.col]))
            {continue;} //computer retries to pick a grid value

            grid[move.row][move.col]='O'; //sets the computer mark
            gridprob[move.row][move.col]=-1;
            sleep(1.5);

            no_of_turns++;
        }

        displayTicTacToe(grid);

        win=winner(grid);
        if(win==0) {continue;}
        else if(win==10)
        {
            printf("You Win!\n");
            break;
        }
        else if(win==-10)
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

void displayTicTacToe(char grid[3][3])
{
    printf("\033[2J\033[H"); //to clear the screen if any grid is already present

    printf("   a   b   c\n");

    for(int i=0;i<3;i++)
    {
        printf("%d: %c | %c | %c\n",i+1,grid[i][0],grid[i][1],grid[i][2]);
        if(i!=2){printf("----------------\n");}
    }
}

bool invalidInput(Move *move,char col)
{
    if(move->row>2 || move->row<0)
    {
        printf("Invalid values\n");
        return true;
    }

    if(col=='a' || col=='A')
    {
        move->col=0;
        return false;
    }
    else if(col=='b' || col=='B')
    {
        move->col=1;
        return false;
    }
    else if(col=='c' || col=='C')
    {
        move->col=2;
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
    if(grid_val==' ') {return false;}

    return true;
}

int winner(char grid[3][3])
{
    for(int i=0;i<3;i++)
    {
        if( (grid[i][0]== 'X' && grid[i][1]== 'X' && grid[i][2]== 'X') || //columns
            (grid[0][i]== 'X' && grid[1][i]== 'X' && grid[2][i]== 'X') || //rows
            (grid[0][0]== 'X' && grid[1][1]== 'X' && grid[2][2]== 'X') || //diagonals
            (grid[2][0]== 'X' && grid[1][1]== 'X' && grid[0][2]== 'X')  )   
            
        {return 10;} //player win


        else if((grid[i][0]== 'O' && grid[i][1]== 'O' && grid[i][2]== 'O') || //columns
                (grid[0][i]== 'O' && grid[1][i]== 'O' && grid[2][i]== 'O') || //rows
                (grid[0][0]== 'O' && grid[1][1]== 'O' && grid[2][2]== 'O') || //diagonals
                (grid[2][0]== 'O' && grid[1][1]== 'O' && grid[0][2]== 'O')  )
                
        {return -10;} //computer win
    }
    return 0; //noone won yet
}

void minimax(char grid[3][3],int depth,bool isComputer)
{
    int max=1000;
}

