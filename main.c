#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include </workspaces/mini-arcade-C/tictactoe.c>
#include </workspaces/mini-arcade-C/rock_paper_scissors.c>
#include </workspaces/mini-arcade-C/calcgame.c>
#include </workspaces/mini-arcade-C/hangman.c>
#include </workspaces/mini-arcade-C/tower_of_hanoi.c>
#include </workspaces/mini-arcade-C/memory-game.c>
#include </workspaces/mini-arcade-C/snake.c>
#include </workspaces/mini-arcade-C/minesweeper.c>
#include </workspaces/mini-arcade-C/connect_four.c>
#include </workspaces/mini-arcade-C/jumble.c>

/* ── ANSI colour codes ─────────────────────────────── */
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define PURPLE  "\033[35m"
#define BPURPLE "\033[95m"   /* bright purple  */
#define CYAN    "\033[96m"
#define WHITE   "\033[97m"
#define DIM     "\033[2m"
#define YELLOW  "\033[93m"

/* ── prototypes ────────────────────────────────────── */
void clearScreen();
void printBlock(const char *text, int fillLine);
void printPair(int n1, const char *g1, int n2, const char *g2);
void showMainMenu();
void bootScreen();
void loadingScreen(const char *gameName);
void returnScreen(const char *gameName);


void clearScreen() {
    system("clear");
}


/* Prints two menu items side by side */
void printPair(int n1, const char *g1, int n2, const char *g2) {
    char left[32], right[32];

    if (n1 >= 0)
        snprintf(left,  sizeof(left),  "%s[%2d]%s %-16s", YELLOW, n1, WHITE, g1);
    else
        snprintf(left,  sizeof(left),  "%-22s", "");

    if (n2 >= 0)
        snprintf(right, sizeof(right), "%s[%2d]%s %-16s", YELLOW, n2, WHITE, g2);
    else
        snprintf(right, sizeof(right), "%-22s", "");

    printf("  %s    %s\n", left, right);
}



void bootScreen() {
    clearScreen();

    printf("\n");
    printf(BPURPLE ".......................\n" RESET);
    printf(RESET BOLD CYAN "   MINI RETRO ARCADE  " RESET BPURPLE "\n" RESET);
    printf(BPURPLE ".......................\n" RESET);

    const char *steps[] = {
        "  Charging cells             ",
        "  Warming up                 ",
        "  Inserting coins            ",
        "  System ready!              "
    };
    for (int i = 0; i < 4; i++) {
        printf(PURPLE "%s" RESET, steps[i]);
        fflush(stdout);
        sleep(1);
        printf(CYAN " [OK]\n" RESET);
    }

    printf("\n" YELLOW "  Press ENTER to start..." RESET);
    getchar();
}

void showMainMenu() {
    clearScreen();
    printf("\n");

    printf(BOLD CYAN "  ★  M I N I   R E T R O   A R C A D E  ★  " RESET);
    printf("\n\n\n");


    printPair( 1, "Tower of Hanoi",      2, "Snake");
    printf("\n");
    printPair( 3, "Tic-Tac-Toe",         4, "Minesweeper");
    printf("\n");
    printPair(5, "Hangman" ,       6, "Connect Four");
    printf("\n");
    printPair(7, "Jumble",              0, "Exit");

    /* Footer */
    printf("\n");
   
    printf(BOLD WHITE "  INSERT COIN: " RESET CYAN);
}

void loadingScreen(const char *gameName) {
    clearScreen();
    printf("\n");
    printf(BPURPLE "..............................\n" RESET);
    printf(BPURPLE "." RESET BOLD CYAN "  LOADING %-30s" RESET BPURPLE ".\n" RESET, gameName);
    printf(BPURPLE "..............................\n" RESET);

    printf("  " PURPLE);
    int total = 20;
    for (int i = 0; i <= total; i++) {
        printf(".");
        fflush(stdout);
        usleep(70000);  /* 40 ms per block — snappy but visible */
    }
    printf(RESET "\n\n");
    sleep(1);
    clearScreen();
}

void returnScreen(const char *gameName) {
    sleep(2);
    clearScreen();
    printf("\n");
    printf(BPURPLE "..............................\n" RESET);
    printf(BPURPLE "." RESET BOLD YELLOW "  ✓ GAME OVER  —  %-22s" RESET BPURPLE ".\n" RESET, gameName);
    printf(BPURPLE "." RESET CYAN "  Returning to arcade...              " RESET BPURPLE ".\n" RESET);
    printf(BPURPLE "..............................\n" RESET);
    sleep(2);
}



int main() {
    int choice;
    bootScreen();

    const char *names[] = {
        "", "Tower of Hanoi", "Snake", "Tic-Tac-Toe",
        "Minesweeper", "Hangman",
        "Connect Four", "Jumble"
    };

    
    while (1) {
        showMainMenu();

        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        printf(RESET "\n");

        if (choice == 0) {
            clearScreen();
            printf("\n");
            printf(BPURPLE "........................................\n" RESET);
            printf(BPURPLE "." RESET BOLD YELLOW "   THANKS FOR PLAYING — GAME OVER      " RESET BPURPLE ".\n" RESET);
            printf(BPURPLE "." RESET CYAN "   Insert coin to continue...          " RESET BPURPLE ".\n" RESET);
            printf(BPURPLE ".........................................3\n" RESET);
            return 0;
        }

        if (choice < 1 || choice > 11) {
            printf(YELLOW "  Invalid choice! Enter 0–11.\n" RESET);
            sleep(2);
            continue;
        }

        loadingScreen(names[choice]);

        switch (choice) {
            case  1: start_toh();               break;
            case  2: start_snake();             break;
            case  3: start_tictactoe();         break;
            case  4: start_minesweeper();       break;
            
        

            case  5: start_hangman();           break;
         
            case 6: start_connect_four();      break;
            case 7: start_jumble();            break;
        

        }

        sleep(3);
        returnScreen(names[choice]);
    }

    return 0;
}
