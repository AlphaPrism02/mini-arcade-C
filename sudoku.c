#include<stdio.h>

int start_sudoku()
{
    int sudoku[4][4] = {
        {1,0,0,4},
        {0,4,1,0},
        {2,0,4,3},
        {0,3,2,0}
    };

    int row, col, num, i;
    int valid;

    printf("===== MINI SUDOKU (4x4) =====\n");
    printf("Fill numbers from 1 to 4\n\n");

    while(1)
    {
        // Display Grid
        printf("\nCurrent Sudoku Grid:\n");

        for(row = 0; row < 4; row++)
        {
            for(col = 0; col < 4; col++)
            {
                if(sudoku[row][col] == 0)
                    printf(". ");
                else
                    printf("%d ", sudoku[row][col]);
            }
            printf("\n");
        }

        // Take Position Input
        printf("\nEnter row (1-4): ");
        scanf("%d", &row);

        printf("Enter column (1-4): ");
        scanf("%d", &col);

        row--;
        col--;

        // Prevent overwrite
        if(sudoku[row][col] != 0)
        {
            printf("Cell already filled!\n");
            continue;
        }

        // Take Number Input
        printf("Enter value (1-4): ");
        scanf("%d", &num);

        valid = 1;

        // Row Validation
        for(i = 0; i < 4; i++)
        {
            if(sudoku[row][i] == num)
                valid = 0;
        }

        // Column Validation
        for(i = 0; i < 4; i++)
        {
            if(sudoku[i][col] == num)
                valid = 0;
        }

        // 2x2 Box Validation
        int startRow = row - row % 2;
        int startCol = col - col % 2;

        for(int r = startRow; r < startRow + 2; r++)
        {
            for(int c = startCol; c < startCol + 2; c++)
            {
                if(sudoku[r][c] == num)
                    valid = 0;
            }
        }

        // Insert if Valid
        if(valid)
        {
            sudoku[row][col] = num;
            printf("Value inserted successfully!\n");
        }
        else
        {
            printf("Invalid Move! Number violates Sudoku rules.\n");
        }

        // Continue Option
        int choice;
        printf("Continue? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);

        if(choice == 0)
            break;
    }

    // Final Grid
    printf("\nFinal Sudoku Grid:\n");

    for(row = 0; row < 4; row++)
    {
        for(col = 0; col < 4; col++)
        {
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }

    return 0;
}