#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;
    do
    {
        Height =  get_int("Height: ");
    }
    while (Height > 8 || Height < 1);
    for (int i = 1; i <= Height; i++)
    {
        //This loop will print spaces
        for (int k = 0; k < Height - i; k++)
        {
            printf(" ");    
        }
        //This loop will print #s
        for (int j = 1; j <= i; j++)
        {
            printf("#");
           
        }
        //prints the aisle between the two pyramids
        printf("  ");
        //prints the seconed pyramid
        for (int j = 1; j <= i; j++)
        {
            printf("#");
           
        }
      
        printf("\n");
    }
    
}
