#include<stdio.h>

int start_sudoku()
{
    int sudoku[4][4]={
        {1,0,0,4},
        {0,4,1,0},
        {2,0,4,3},
        {0,3,2,0}
    };
    int row,col,num;

    printf("MINI SUDOKU (4x4)\n");
    printf("Fill numbers from 1 to 4\n\n");

    while(1)
    {
        printf("Your current Sudoku grid:\n");
        for(row=0; row<4; row++)
        {
            for(col=0; col<4; col++)
                {
                    if(sudoku[row][col]==0)
                        printf(" . ");
                    else
                        printf(" %d ",sudoku[row][col]);
                }   
                printf("\n");
        }

        printf("\nEnter row (1-4): ");
        scanf("%d",&row);
        printf("Enter col (1-4): ");
        scanf("%d",&col);

        row--;
        col--;

        if(sudoku[row][col]!= 0)
        {
            printf("Cell already filled!\n");
            continue;
        }

        printf("Enter value (1-4): ");
        scanf("%d",&num);

        sudoku[row][col] = num;

        printf("Continue? (1=Yes, 0=No): ");
        int choice;
        scanf("%d",&choice);

        if(choice == 0)
            break;
    }

    printf("\nYour Final Sudoku:\n");
    for(row=0; row<4; row++)
    {
        for(col=0; col<4; col++)
        {
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
    return 0;
}
