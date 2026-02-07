#include <stdio.h>
#include <string.h>

// Function to display hangman based on lives
void hangman(int lives) {
    if (lives == 5)
        printf("\n O\n/|\\\n/ \\ ");
    else if (lives == 4)
        printf("\n O\n/|\\\n/ ");
    else if (lives == 3)
        printf("\n O\n/|\\ ");
    else if (lives == 2)
        printf("\n O\n/| ");
    else if (lives == 1)
        printf("\n O\n | ");  
    else if (lives == 0)
        printf("\n O ");   
}

// Main game logic
void playLevel(char word[]) {
    int length = strlen(word);
    char guess[20];
    char letter;
    int lives = 6;
    int found, win = 0;

    for (int i = 0; i < length; i++)
        guess[i] = '_';
    guess[length] = '\0';

    while (lives > 0 && !win) {
        found = 0;

        printf("\nWord: %s", guess);
        printf("\nLives: %d", lives);
        hangman(lives);
        printf("\nEnter a letter: ");
        scanf(" %c", &letter);

        for (int i = 0; i < length; i++) {
            if (word[i] == letter && guess[i] == '_') {
                guess[i] = letter;
                found = 1;
            }
        }

        if (!found) {
            lives--;
            printf("Wrong guess!");
        } else {
            printf("Correct!");
        }

        if (strcmp(word, guess) == 0)
            win = 1;
    }

    if (win)
        printf("\n Level Cleared!");
    else {
        printf("\n You Lost! Word was: %s", word);
        exit(0);
    }
}

void start_hangman() {
    printf("HANGMAN GAME IN C \n");

    char levels[5][20] = {
    "array",            // Level 1
    "pointer",          // Level 2
    "compiler",         // Level 3
    "algorithm",        // Level 4
    "dataabstraction"   // Level 5

    };

    for (int i = 0; i < 5; i++) {
        printf("\n\n--- LEVEL %d ---\n", i + 1);
        playLevel(levels[i]);
    }

    printf("\n CONGRATULATIONS! You completed all levels!");
}
