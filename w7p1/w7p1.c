/*
*****************************************************************************
                    Workshop - #7 (P1)
Full Name : Xuan Khang Huynh(Cris Huynh)
Student ID# : 10544428
Email : xhuynh@myseneca.ca
Section : BTP100 NCC
Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
* ****************************************************************************
*/


#define _CRT_SECURE_NO_WARNINGS
#define MIN_LIVE 1
#define MAX_LIVE 10
#define MIN_PATH 10
#define MAX_PATH 70
#define MIN_LIMIT 3
#define MAX_LIMIT 26

#include <stdio.h>

struct PlayerInfo
{
    char Character;
    int Lives;
};

struct GameInfo
{
    int Path;
    int Bomb[MAX_PATH];
    int Treasure[MAX_PATH];
    int Limit;
    int History[MAX_PATH];
};


int main(void)
{
    int flag = 0;
    int i = 0;
    int j, nrows, mrows;

    struct PlayerInfo Player;
    struct GameInfo Game;


    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &Player.Character);

    do
    {
        printf("Set the number of lives: ");
        scanf("%d", &Player.Lives);

        if (Player.Lives < MIN_LIVE || Player.Lives > MAX_LIVE)
            printf("     Must be between 1 and 10!\n");

        else
            flag = 1;

    } while (flag == 0);

    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");

    do
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &Game.Path);
        if (Game.Path % 5 != 0 || Game.Path < MIN_PATH || Game.Path > MAX_PATH)
            printf("     Must be a multiple of 5 and between 10-70!!!\n");

        else
            flag = 0;

    } while (flag == 1);

    do
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &Game.Limit);

        if (Game.Limit < MIN_LIMIT || Game.Limit > MAX_LIMIT)
            printf("    Value must be between 3 and 26\n");
        else
            flag = 1;

    } while (flag == 0);

    // BOMB PLACEMENT
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");


    nrows = Game.Path / 5;
    for (i = 0; i < nrows; i++)
    {
        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &Game.Bomb[(i * 5 + j)]);
        }

    }
    printf("BOMB placement set\n\n");


    // TREASURE PLACEMENT
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

    mrows = Game.Path / 5;
    for (i = 0; i < mrows; i++)
    {
        /*     if ( i == 1)
             printf("     Positions [ %d- %d]: ", (i * 5) + 1, (i * 5) + 5);

             else if (i == 2)
             printf("     Positions [ %d-%d]: ", (i * 5) + 1, (i * 5) + 5);

             else if (i > 2)
             printf("     Positions [%d-%d]: ", (i * 5) + 1, (i * 5) + 5);

             scanf("%d %d %d %d %d", &Game.Treasure[i * 5 - 5], &Game.Treasure[i * 5 - 4], &Game.Treasure[i * 5 - 3], &Game.Treasure[i * 5 - 2], &Game.Treasure[i * 5 - 1]);*/

        printf("   Positions [%2d-%2d]: ", (i * 5) + 1, (i * 5) + 5);
        for (j = 0; j < 5; j++)
        {
            scanf("%d", &Game.Treasure[(i * 5 + j)]);
        }

    }

    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    printf("Player:\n");
    printf("   Symbol     : %c\n", Player.Character);
    printf("   Lives      : %d\n", Player.Lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", Game.Path);
    printf("   Bombs      : ");
    for (i = 0; i < Game.Path; i++)
    {
        printf("%d", Game.Bomb[i]);
    }
    printf("\n   Treasure   : ");
    for (i = 0; i < Game.Path; i++)
    {
        printf("%d", Game.Treasure[i]);
    }


    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}