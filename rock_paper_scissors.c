#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer;
    int userScore = 0, compScore = 0;

    srand(time(NULL));

    printf("ROCK PAPER SCISSORS\n");
    printf("First to 5 points WINS!\n\n");

    char *choices[] = {"Rock", "Paper", "Scissors"};

    while (userScore < 5 && compScore < 5) {
        printf("\nChoose:\n");
        printf("0 -> Rock\n1 -> Paper\n2 -> Scissors\n");
        printf("Your choice: ");
        scanf("%d", &user);

        if (user < 0 || user > 2) {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        computer = rand() % 3;

        printf("You chose: %s\n", choices[user]);
        printf("Computer chose: %s\n", choices[computer]);

        if (user == computer) {
            printf("Draw! No points.\n");
        }
        else if ((user == 0 && computer == 2) ||
                 (user == 1 && computer == 0) ||
                 (user == 2 && computer == 1)) {
            printf("You win this round!\n");
            userScore++;
        }
        else {
            printf("Computer wins this round!\n");
            compScore++;
        }

        printf("SCORE - You: %d | Computer: %d\n", userScore, compScore);
    }

    if (userScore == 5)
        printf("\n YOU WON THE MATCH! \n");
    else
        printf("\n COMPUTER WON THE MATCH \n");

    return 0;
}
