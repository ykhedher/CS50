#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
    float Change;
    int cents = 0, dollar = 0;
    do
    {
        Change = get_float("Change_owed: ");
    }
    while (Change < 0);
    if ((int) Change > 0)
    {
        dollar = ((int) Change);
        //number of cents (25)
        cents = (dollar * 100) / 25;
    }
    //the new change
    int New_change = round((Change - dollar) * 100);
    if (New_change != 0) //true
    {
        do //repeat
        {
       
            if (New_change >= 25)
            {
                //subtract 25 from change and add one to cents
                New_change -= 25; //true 
                cents++;
            }
            else if (New_change >= 10 && New_change < 25)
            {
                //subtract 10 from change and add one to cents
                New_change -= 10;
                cents++;

            }
            else if (New_change >= 5 && New_change < 10)
            {
                //subtract 5 from change and add one to cents
                New_change -= 5;
                cents++;

            }
            else if (New_change == 1)
            { 
                //subtract 5 from change and add one to cents
                cents++; 
                New_change--;
            }
        } // stop when change is 0
        while (New_change != 0);
    }
    printf("%i\n", cents);
    
    
}
