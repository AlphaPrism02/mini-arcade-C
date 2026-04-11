#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

typedef struct
{
    int row,col;
}Move;


void displayTicTacToe(char[3][3]);
bool invalidInput(Move*,char);
bool occupied(char);
int winner(char[3][3]);
int minimax(char[3][3],int,bool,int);
Move easyDiffMove(char[3][3]);
Move medDiffMove(char[3][3],int);
Move hardDiffMove(char[3][3],int);



void start_tictactoe()
{
    int difficulty;
    printf("Select Difficulty:\n1.Easy\n2.Medium\n3.Hard\n");
    scanf("%d",&difficulty);

    while(difficulty<1||difficulty>3)
    {
        printf("Invalid Difficulty\n");
        int ch;
        while ((ch=getchar())!='\n' && ch!=EOF); //waits for the input to clear
        scanf("%d",&difficulty);
    }

    
    printf("Tic Tac Toe:\nOn your turn, enter coordinates of the grid.\nFor Example: 1a for the first square of the first column\n");

    char grid[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    displayTicTacToe(grid);

    srand(time(NULL)); // seed ONCE
    int no_of_turns=0,player;

    if(rand()%2==0)//Start can be either ai or player
    {
        player=1;
    }
    else
    {
        player=0;
    }

    Move move;
    int score;
    char col;

    while(no_of_turns<9)
    {
        if(no_of_turns%2==player) //player turn
        {
            sleep(1);
            printf("Your Turn:");
            scanf("%d %c",&move.row,&col);
            move.row--; //We take 1,2,3 as input so we need to row-1 to correct the inputs

            if(invalidInput(&move,col) || occupied(grid[move.row][move.col])) 
            {
                if(grid[move.row][move.col]=='X') {printf("You already played there\n");}

                else if(grid[move.row][move.col]=='O') {printf("The computer has played there\n");}

                int ch;
                while ((ch=getchar())!='\n' && ch!=EOF); //waits for the input to clear
                continue;
            }  //allows the user to re-enter the values without going thru the rest of the code

            grid[move.row][move.col]='X';    //sets the player mark

            no_of_turns++;
        }
        else //computer turn
        {
            if(difficulty==1)
            {
                move=easyDiffMove(grid);
            }
            else if(difficulty==2)
            {
                move=medDiffMove(grid,no_of_turns);
            }
            else
            {
                move=hardDiffMove(grid,no_of_turns);
            }

            grid[move.row][move.col]='O'; //sets the computer mark
            sleep(1);

            no_of_turns++;
        }

        displayTicTacToe(grid);
        
        score=winner(grid);
        if(score==-10)
        {
            printf("You Win!\n");
            break;
        }
        else if(score==+10)
        {
            printf("You Lose :(\n");
            break;
        }
        else if(score==0 && no_of_turns==9)
        {
            printf("Tied -_-\n");
            break;
        }
        else {continue;}
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
            
        {return -10;} //player score


        else if((grid[i][0]== 'O' && grid[i][1]== 'O' && grid[i][2]== 'O') || //columns
                (grid[0][i]== 'O' && grid[1][i]== 'O' && grid[2][i]== 'O') || //rows
                (grid[0][0]== 'O' && grid[1][1]== 'O' && grid[2][2]== 'O') || //diagonals
                (grid[2][0]== 'O' && grid[1][1]== 'O' && grid[0][2]== 'O')  )
                
        {return +10;} //computer score
    }
    return 0; //noone won yet
}

Move easyDiffMove(char grid[3][3])
{
    Move move;

    do
    {
        move.row=rand()%3;
        move.col=rand()%3;
    } while(occupied(grid[move.row][move.col]));

    return move;
}

Move medDiffMove(char grid[3][3],int no_of_turns)
{
    Move move;

    if(no_of_turns==0)
    {
        move.row=1;
        move.col=1;
        return move;
    }
    else if(no_of_turns==1)
    {
        if(grid[1][1]=='X')
        {
            move.row=rand()%2*2; //0 or 2
            move.col=rand()%2*2;
        }
        else
        {
            move.row=1;
            move.col=1;
        }
        return move;
    }
    else
    {
        for(int i=0;i<3;i++)
        {
            // rowwise check for 2 X's to block player from winning
            if(grid[i][0]=='X' && grid[i][1]=='X' && grid[i][2]==' ')
            {
                move.row=i;
                move.col=2;
                return move;
            }
            else if(grid[i][0]=='X' && grid[i][1]==' ' && grid[i][2]=='X')
            {
                move.row=i;
                move.col=1;
                return move;
            }
            else if(grid[i][0]==' ' && grid[i][1]=='X' && grid[i][2]=='X')
            {
                move.row=i;
                move.col=0;
                return move;
            }

            // columnwise check for 2 X's to block player from winning
            else if(grid[0][i]=='X' && grid[1][i]=='X' && grid[2][i]==' ')
            {
                move.row=2;
                move.col=i;
                return move;
            }
            else if(grid[0][i]=='X' && grid[1][i]==' ' && grid[2][i]=='X')
            {
                move.row=1;
                move.col=i;
                return move;
            }
            else if(grid[0][i]==' ' && grid[1][i]=='X' && grid[2][i]=='X')
            {
                move.row=0;
                move.col=i;
                return move;
            }
        }

        //diagonal check for 2 X's to block player from winning
        
        //left diag
        if(grid[0][0]=='X' && grid[1][1]=='X' && grid[2][2]==' ')
        {
            move.row=2;
            move.col=2;
            return move;
        }
        else if(grid[0][0]=='X' && grid[1][1]==' ' && grid[2][2]=='X')
        {
            move.row=1;
            move.col=1;
            return move;
        }
        else if(grid[0][0]==' ' && grid[1][1]=='X' && grid[2][2]=='X')
        {
            move.row=0;
            move.col=0;
            return move;
        }

        //right diag
        else if(grid[2][0]=='X' && grid[1][1]=='X' && grid[0][2]==' ')
        {
            move.row=0;
            move.col=2;
            return move;
        }
        else if(grid[2][0]=='X' && grid[1][1]==' ' && grid[0][2]=='X')
        {
            move.row=1;
            move.col=1;
            return move;
        }
        else if(grid[2][0]==' ' && grid[1][1]=='X' && grid[0][2]=='X')
        {
            move.row=2;
            move.col=0;
            return move;
        }

        //if no move to block player from winning, play random move
        move.row=rand()%3;
        move.col=rand()%3;
        return move;
    }
}

int minimax(char grid[3][3],int depth,bool isComputer,int no_of_turns)
{
    int score=winner(grid);

    if(score==10 || score==-10) {return score;} //if computer wins or player wins return score and get best move

    if(no_of_turns==9) {return 0;} //if tie return 0 since that will be the best outcome for the computer
    
    if(isComputer)
    {
        int bestScore=-100;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]!=' ') {continue;} //skip occupied cells

                grid[i][j]='O'; //computer move
                int score=minimax(grid,depth+1,false,no_of_turns+1);
                grid[i][j]=' '; //undo move

                bestScore=(score>bestScore)?score:bestScore; //max the computer score
            }
        }
        return bestScore;
    }
    else
    {
        int bestScore=100;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[i][j]!=' ') {continue;} //skip occupied cells

                grid[i][j]='X'; //player move
                int score=minimax(grid,depth+1,true,no_of_turns+1);
                grid[i][j]=' '; //undo move

                bestScore=(score<bestScore)?score:bestScore; //min the player score
            }
        }
        return bestScore;
    }
}

Move hardDiffMove(char grid[3][3],int no_of_turns)
{
    int bestScore=-100;
    Move bestMove;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i][j]!=' ') {continue;} //skip occupied cells

            grid[i][j]='O'; //computer move
            int score=minimax(grid,0,false,no_of_turns+1);
            grid[i][j]=' '; //undo move

            if(score>bestScore)
            {
                bestScore=score;
                bestMove.row=i;
                bestMove.col=j;
            }
        }
    }
    return bestMove;
}