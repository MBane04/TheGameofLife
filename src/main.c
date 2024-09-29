#include <stdio.h>
#include <stdlib.h>
//#include <fstream>
//#include <sstream>
#include <GL/glut.h>
#include <unistd.h>
#include <time.h>
//include <Windows.h>

#include "conway.h"


//https://www.youtube.com/watch?v=O3hxu9K4g2I&list=PLysLvOneEETPFaXD-E6OYwLBW70UjK3QO&index=1
//40:02

void printTable(char **table, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", table[i]);
        printf("\n\n");
    }
}
int main()
{

    printf("Hello world\n");

    //Board dimensions
    #define X 30
    #define Y 100

    conway c;
    startUp(&c, 1, X, Y);
    char *seed[X] = {
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                1                                                                   ",
        "                              1 1                                                                   ",
        "                    11      11            11                                                        ",
        "                   1   1    11            11                                                        ",
        "        11        1     1   11                                                                      ",
        "        11        1   1 11    1 1                                                                   ",
        "                  1     1       1                                                                   ",
        "                   1   1                                                                            ",
        "                    11                                                                              ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    ",
        "                                                                                                    "};

    initTable(&c, seed, ' ');

    int numberOfRounds = 8000000;
    char **output = conwayPrint(&c, '0', ' ', NULL);
    printTable(output, c.x);
    //system("clear");
    
    while(numberOfRounds--)
    {
        conwaySimulate(&c);
        output = conwayPrint(&c, '0', ' ', NULL);
        printTable(output, c.x);
        usleep(10000);
        system("clear");
    }

    if (output != NULL)
    {
        for (int x = 0; x < c.x; x++)
        {
            free(output[x]);
        }
        free(output);
    }

    conwayDestroy(&c);
    return 0;
}