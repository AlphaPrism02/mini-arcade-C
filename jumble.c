#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int start_jumble()
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
int i, length,score=0,attempt ;

srand(time(0));

printf("=== JUMBLE GAME ===\n Play unitl u lose\n");

while(1)
{
    attempt=3-(score/5);
    if(attempt<1)
        attempt=1;

    int index = rand() % (sizeof(words) / sizeof(words[0]));
    strcpy(word, words[index]);
    strcpy(jumble, word);

    length=strlen(jumble);

    for (i=0 ; i<length; i++)
    {
        int j = rand() % length;
        char here = jumble[i];
        jumble[i] = jumble[j];
        jumble[j] = here;
    }
    
    if(strcmp(jumble, word)==0)
        continue;
    
    printf("Unscramble the word:\n");
    printf("%s\n", jumble);



    while (attempt>0)
    {
        printf("Enter your guess : ",attempt);
        scanf("%19s", guess);

        if (strcmp(guess, word) == 0)
        {
            score++;
            printf("Correct! Score: %d\n\n", score);
            break;
        }
        else
        {
            attempt--;
            printf("Wrong ! Attempts left: %d\n", attempt);
        }
    }

    if(attempt==0)
    {
        printf("\nGAME OVER!\n");
        printf("Final Score : %d\n",score);
        printf("Correct Word was, %s\n",word);
        break;
    }
}

return 0;

}
