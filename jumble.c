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
int i, length, attempt = 3;

srand(time(0));

int index = rand() % (sizeof(words) / sizeof(words[0]));
strcpy(word, words[index]);
strcpy(jumble, word);

length = strlen(jumble);

for(i = 0; i < length; i++)
{
    int j = rand() % length;
    char here = jumble[i];
    jumble[i] = jumble[j];
    jumble[j] = here; 
}

printf("Welcome to the JUMBLE GAME\n");
printf("Unscramble the word:\n");
printf("%s\n", jumble);

while (attempt > 0)
{
    printf("Enter your guess : ");
    scanf("%s", guess);

    if (strcmp(guess, word) == 0)
    {
        printf("Correct , You win !\n");
        return 0;
    }
    else
    {
        attempt--;
        printf("Wrong ! Attempts left: %d\n", attempt);
    }
}

printf("GAME OVER! The correct word was : %s\n", word);
return 0;

}
