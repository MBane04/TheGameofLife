#include <stdio.h>

#define WIDTH 26 //201x201 after 
#define HEIGHT 26

#define BACKGROUND '-'


char grid[HEIGHT][WIDTH];

void gridSetup()
{
    for(size_t i = 0; i < HEIGHT; i++)
    
        for(size_t j = 0; j < WIDTH; j++)
        {
            grid[i][j] = '-';
        }
     
}

void gridPrint()
{
    for(size_t i = 0; i < HEIGHT; i++)
    {
        for(size_t j = 0; j < WIDTH; j++)
        {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    gridSetup();
    gridPrint();
    return 0;
}