//https://www.youtube.com/watch?v=I0ndY1Y4avQ&list=PLRnI_2_ZWhtCcyinpkAbk5M2A4UhdOP3A&index=1
//4:45

#include <stdio.h>

#define WIDTH 26 //201x201 after 
#define HEIGHT 26

#define BACKGROUND '-'
#define CELL '#'


char grid[HEIGHT][WIDTH];

void gridSetup()
{
    for(size_t i = 0; i < HEIGHT; i++)
    
        for(size_t j = 0; j < WIDTH; j++)
        {
            grid[i][j] = 'BACKGROUND';
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
    grid[HEIGHT/2][WIDTH/2] = CELL;  
    gridPrint();
    return 0;
}