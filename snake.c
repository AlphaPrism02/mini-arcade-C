#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int width = 20, height = 20;
int x, y, foodX, foodY, score;
int tailX[100], tailY[100];
int ntail;
int gameover;
enum eDirection {STOP = 0, LEFT,RIGHT,UP,DOWN};
enum eDirection dir;

void setup()
{
    gameover = 0;
    dir = STOP;
    x = width/2;
    y = height/2;
    srand(time(0));
    foodX = rand()%width;
    foodY = rand()%height;
    score = 0;
}

void draw()
{
    for (int i=0;i<30;i++)
    {
        printf("\n");
    }
    for (int i=0;i<width+2;i++)
    {
        printf("#");
    }
	printf("\n");
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (j == 0)
            {
                printf("#");
            }
	    else if (i == y && j == x)
	    {
	     	printf("O");
	    }
            else if (i == foodY && j == foodX)
            {
                printf("F");
            }
            else
            {
                int printtail = 0;
                for (int k=0;k<ntail;k++)
                {
                    if (tailX[k]==j && tailY[k]==i)
                    {
                        printf("o");
                        printtail = 1;
                    }
                }
                if (!printtail)
                {
                    printf(" ");
                }
            }
        
            if (j == width-1)
            {
                printf("#");
            }
        }
    
    printf("\n");
    }
    for(int i =0;i < width+2; i++)
    {
        printf("#");
    }
    printf("\nScore: %d\n", score);
    printf("Enter W A S D (X to exit): ");
}
void input() 
{
    char ch;
    scanf(" %c", &ch);
    switch (ch) 
    {
    case 'a': case 'A': dir = LEFT; break;
    case 'd': case 'D': dir = RIGHT; break;
    case 'w': case 'W': dir = UP; break;
    case 's': case 'S': dir = DOWN; break;
    case 'x': case 'X': gameover = 1; break;
    }
}

void logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i =1;i<ntail;i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) 
    {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }
    
    if (x>=width || x<0 || y>=height || y<0)
    gameover = 1;

    for (int i =0;i<ntail;i++)
    {
        if (tailX[i]==x && tailY[i]==y)
        gameover = 1;
    }
    if (x == foodX && y == foodY)
    {
        score +=10;
        foodX = rand()%width;
        foodY = rand()%height;
        ntail++;
    }

}

int main()
{
    setup();
    while(!gameover)
    {
        draw();
        input();
        logic();
    }
    printf("\nGame Over! Final Score = %d\n", score);
    return 0;
}