#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    char words[][20] = {
"computer","keyboard","monitor","mouse","printer",
"scanner","laptop","server","client","internet",
"browser","google","search","website","coding",
"program","compile","debug","output","input",
"screen","window","folder","file","system",
"software","hardware","memory","storage","network",
"signal","data","logic","error","update",
"download","upload","password","login","cloud",
"robot","sensor","camera","battery","mobile",
"tablet","cursor","pixel","image","video",
"audio","speaker","button","click","drag",
"scroll","copy","paste","delete","save",
"print","run","build","design","project",
"model","engine","machine","control","digital",
"binary","number","code","loop","array",
"string","float","integer","function","return",
"break","switch","case","header","library",
"main","printf","scanf","pointer","stack",
"queue","graph","sort","searching","timer",
"random","score","level","game","data",
"train","test","label","pattern","predict",
"learn","vision","speech","text","chart",
"table","filter","cluster","class","feature",
"result","dataset","trend","matrix","vector",
"force","energy","power","speed","motion",
"mass","weight","gravity","light","sound",
"heat","wave","field","charge","current",
"voltage","magnet","atom","electron","proton",
"neutron","space","planet","earth","moon",
"sun","star","galaxy","rocket","orbit",
"time","distance","pressure","density","angle",
"circle","radius","volume","meter","second"
    };

    char word[20], jumble[20], guess[20];
    int i, length, score = 0, attempt;
    int difficulty;

    srand(time(0));

    printf("=== JUMBLE GAME ===\n");

    while (1)
    {
        printf("\nChoose Difficulty:\n");
        printf("1. Easy \n");
        printf("2. Medium \n");
        printf("3. Hard \n");
        printf("Enter choice: ");
        scanf("%d", &difficulty);

        // pick valid word based on difficulty
        while (1)
        {
            int index = rand() % (sizeof(words) / sizeof(words[0]));
            strcpy(word, words[index]);
            length = strlen(word);

            if ((difficulty == 1 && length == 5) ||
                (difficulty == 2 && (length == 6 || length == 7)) ||
                (difficulty == 3 && length >= 8))
                break;
        }

        strcpy(jumble, word);

        // jumble logic
        for (i = 0; i < length; i++)
        {
            int j = rand() % length;
            char temp = jumble[i];
            jumble[i] = jumble[j];
            jumble[j] = temp;
        }

        if (strcmp(jumble, word) == 0)
            continue;

        attempt = 3;

        printf("\nUnscramble: %s\n", jumble);

        while (attempt > 0)
        {
            printf("Enter guess: ");
            scanf("%19s", guess);

            if (strcmp(guess, word) == 0)
            {
                score++;
                printf("Correct! Score: %d\n", score);
                break;
            }
            else
            {
                attempt--;
                printf("Wrong! Attempts left: %d\n", attempt);
            }
        }

        if (attempt == 0)
        {
            printf("\nGAME OVER!\n");
            printf("Final Score: %d\n", score);
            printf("Word was: %s\n", word);
            break;
        }

        // continue option
        int choice;
        printf("\n1. Continue\n2. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 2)
        {
            printf("Final Score: %d\n", score);
            break;
        }
    }

    return 0;
}