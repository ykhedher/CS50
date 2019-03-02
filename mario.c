#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Variable Declaration
    int Height;
    //accepts an integer between 8 and 1   
    do
    {
        Height = get_int("Height: ");
    }
    while (Height > 8 || Height < 1);
    //The first for will add a back to line
    for (int i = 1; i <= Height; i++)
    {
        //This loop will print spaces
        for (int k = 0; k < Height-i; k++)
          {
            printf(" ");    
          }
            //This loop will print #s
            for (int j = 1; j <= i; j++)
              {
                printf("#");
              }
              printf("\n");
    }
}
