#include "conway.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int mod(int n, int d) //modulo
{
    while(n < 0)
    {
        n += d;
    }
    return n%d;
}

int cellWrap(conway *c, int x, int y)//wraps the cells around pac-man style
{
    if(c->wrap) // wraps only if we need to 
    {
        x = mod(x, c->x);
        y = mod(y, c->y);
    }
    else //check values
    {
        if (x < 0 || x >= c->x || y < 0 || y >= c->y )
        {
            return 0;
        }
    }
    return c->board[x * c->y + y]; //return index mapping, rows(x) have the size of c.y, add y to get the column

}

void startUp(conway *c, char wrap, int x, int y) // algorithms
{
    if(!c) //check for invalid pointer
    {
        printf("Invalid Pointer!");
        return;
    }

    if( x < 0 || y < 0) //check for negative dimensions
    {
        printf("Invalid Dimensions!");
        return;
    }

    //pass in values
    c->wrap = wrap;
    c->x = x;
    c->y = y;

    //allocate memory
    c-> board = malloc(x * y);

    // initialize the 2D grid (c.board) by setting all elements to 0
    memset(c->board, 0, x * y);

}


void initLine(conway *c, char *seed, char empty)  // 1D initial state
{
    for(int i = 0, n = c->x * c->y ; i < n; i++)
    {
        //check if the charachter in seed is empty  and assign it as alive or dead
        c->board[i] = seed[i] != empty ? 1 : 0; //c.board[i] = seed[i]; if seed[i] != empty, 1, else 0
    }
}

void initTable(conway *c, char **seed, char empty) //2D(board) initial state
{
    int i = 0; 
    //c.x amnt of strings
    for(int x = 0; x < c->x; x++)
    {
        //each have c-> amnt of chars
        for(int y = 0; y < c->y; y++)
        {
            // check if the charachter in seed is empty  and assign it as alive or dead
            c->board[i] = seed[x][y] != empty ? 1 : 0;
            i++;
        }
    }
}

void conwaySimulate(conway *c)
{
    //temp variable to store our current board so that we don't mess with neighbor counts
    char *temp = malloc(c->x * c->y);


    int i = 0;
    //count active neighbors
    for(int x = 0; x < c->x; x++)
    {
        for(int y = 0; y < c->y; y++)
        {
            int activeNeighbors = 0;
            for(int xi = -1; xi <= 1; xi++)
            {
                for(int yi = -1; yi <= 1; yi++)
                {
                    // if i am alive and my possibly warped neighbors are alive
                    if((xi || yi) && cellWrap(c, x + xi, y + yi))
                    {
                        activeNeighbors++;
                    }
                }
            }
            // lives cells with 2 or 3 neighbors stay alive, a dead cell with 3 neighbors comes to life
            if (c->board[i] && (activeNeighbors == 2 || activeNeighbors == 3)) // if i am alive and have 2 or 3 neighbors
            {
                temp[i] = 1;
            }
            else if (!c->board[i] && activeNeighbors == 3) // if i am dead and have 3 neighbors, I am alive
            {
                temp[i] = 1;
            }
            else // just remain dead
            {
                temp[i] = 0;
            }
            i++;
        }
    }

    //copy temp back to the board
    memcpy(c->board, temp, c->x*c->y);
    free(temp);
    
}

void conwaysimulateN(conway *c, int n)
{
    while (n--)
    {
        conwaySimulate(c);
    }
}

void conwayDestroy(conway *c)
{
    if (c && c->board) // if c & c.board are not null
    {
        c->x = 0;
        c->y = 0;
        free(c->board);
    }
}

char **conway_print(conway *c, char live, char dead, char **ret)
{
    char allocate = 0;
    if (!ret)//if ret is null
    {
        // allocate array of pointers
        ret = malloc(c->x * sizeof(char *));
        if(!ret)
        {
            printf("Memory allocation failed for ret!");
            return NULL;
        }
        allocate = 1;
    }

    //for each row
    int i = 0;
    for(int x = 0; x < c->x; x++)
    {
        //allcoate an array of chars + terminator if return isn't null
        if(allocate)
        {
            ret[x] = malloc(c->y * sizeof(char) + 1);
            if (!ret[x])
            { // Check for allocation failure
                printf("Memory allocation for row %d failed!\n", x);
                // Handle memory cleanup before returning
                for (int j = 0; j < x; j++)
                {
                    free(ret[j]);
                }
                free(ret);
                return NULL;
            }
        }
        for(int y = 0; y < c->y; y++)
        {
            ret[x][y] = c->board[i] ? live : dead;
            i++;
        }
        ret[x][c->y] = '\0';
    }
    
    return ret;
}