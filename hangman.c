#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// func to display lives
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

// main game
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
            printf("\nWrong guess!");
        } else {
            printf("\nCorrect!");
        }

        if (strcmp(word, guess) == 0)
            win = 1;
    }

    if (win)
        printf("\nLevel Cleared!\n");
    else {
        printf("\nYou Lost! Word was: %s\n", word);
        exit(0);
    }
}

// random word
char* getRandomWord() {
    static char words[][20] = {
        "array", "pointer", "compiler", "algorithm", "dataabstraction",
        "function", "variable", "iteration", "recursion", "structure",
        "debugging", "operator", "syntax", "library", "integer"
    };

    int totalWords = sizeof(words) / sizeof(words[0]);
    int index = rand() % totalWords;

    return words[index];
}

// function to start the hangman game
void start_hangman() {
    printf("HANGMAN GAME IN C\n");

    srand(time(0));  // Seed for randomness

    int levels = 5;  // Number of rounds

    for (int i = 0; i < levels; i++) {
        printf("\n\n--- LEVEL %d ---\n", i + 1);
        char *word = getRandomWord();
        playLevel(word);
    }

    printf("\nCONGRATULATIONS! You completed all levels!\n");
}
