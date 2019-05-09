/*
 Author:      Lilian Wang
 Date:        2018.10.04
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_POS 70
#define MAX_STR 32
#define True    1
#define False   0

int randomInt(int);
int timPosition(int);
int harPosition(int);
int checkPos(int);

int main()
{
    srand(time(NULL));

    char mountOfDoom[MAX_POS];//the array of the Mont of Doom

    int run = True;
    int tPos = 0, hPos = 0;

    for(int i = 0; i < MAX_POS; ++i)
    {
        mountOfDoom[i] = ' ';
    }

    while (run)
    {
        tPos = timPosition(tPos);
        hPos = harPosition(hPos);

        if(tPos == hPos)
        {
            mountOfDoom[tPos] = '!';
        }
        else
        {
            mountOfDoom[tPos] = 'T';
            mountOfDoom[hPos] = 'H';
        }

        printf("|");
        for(int i = 0; i < MAX_POS; ++i)
        {
            printf("%c",mountOfDoom[i]);
        }
        printf("|\n");

        if(MAX_POS - 1 == tPos || MAX_POS - 1 == hPos)
        {
            run = False;
            printf("\n");
            if(tPos < hPos)
            {
                printf("Winner is Harold\n");
            }
            else
            {
                if(tPos > hPos)
                {
                    printf("Winner is Timmy\n");
                }
                else
                {
                    printf("Draw!\n");
                }
            }
        }

        for(int i = 0; i < MAX_POS; ++i)
        {
            mountOfDoom[i] = ' ';
        }
    }
    return 0;
}

/*
 * Function:    randomInt
 * Purpose:     returns a random number in the range [0,max)
 * Parameters:
 *      in:     maximum of range
 *      return: randomly generated number
 */

int randomInt(int max)
{
    return(rand() % max);
}

/*
 * Function:    timmyPosition
 * Purpose:     returns the position if Tortoise
 * Parameters:
 *      in:    the previous position of Tortoise
 *      return: the current position of Tortoise
 */
int timPosition(int tCurrPos)
{
    int tRandom = randomInt(100);

    if(tRandom > 0 && tRandom <= 50)
    {
        tCurrPos += 3;
    }
    else
    {
        if( tRandom > 50 && tRandom <= 80)
        {
            tCurrPos += 1;
        }
        else
        {
            tCurrPos -= 6;
        }
    }
    return checkPos(tCurrPos);
}
/*
 * Function:    harolPosition
 * Purpose:     returns the position of Hare
 * Parameters:
 *      in:     the previous position of Hare
 *      return: the current position of Hare
 */
int harPosition(int hCurrPos)
{
    int hRandom = randomInt(100);

    if(hRandom > 0 && hRandom <= 20)
    {
      hCurrPos += 9;
    }
    else
    {
        if (hRandom > 20 && hRandom <= 50)
        {
            hCurrPos += 1;
        }
        else
        {
            if(hRandom > 50 && hRandom <= 60)
            {
                hCurrPos -= 12;
            }
            else
            {
                if(hRandom > 60 && hRandom <= 80)
                {
                    hCurrPos -= 2;
                }
            }
        }
    }

    return checkPos(hCurrPos);
}

/*
 * Function:    checkPos
 * Purpose:     check the runners position,
                if it is a negetive number, return 0;
                if it is bigger than MAX_POS, return MAX_POS-1;
 * Parameters:
 *      in:    the current position of runners
 *      return: the correct position of runners
 */
int checkPos(int currPos)
{
    if(currPos < 0){
        currPos = 0;
    }
    if(currPos > MAX_POS-1)
    {
        currPos = MAX_POS-1;
    }
    return currPos;
}
