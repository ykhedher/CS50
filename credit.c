#include <stdio.h>
#include <cs50.h>
int main(void)
{
    long Credit = get_long("Number: ");
    int count = 0;
    //FIRST TWO DIGITS
    int AMEX = (int)(Credit / 10000000000000);
    //FIRST TWO DIGITS
    int MCARD = (int)(Credit / 100000000000000);
    //FIRST DIGIT IN CASE 13 DIGITS
    int VISA = (int)(Credit / 1000000000000);
    while (Credit > 1)
    {
        Credit /= 10;
        count++;
    }
    //INVALID
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }
    //american-express
    if (count == 15 && (AMEX == 37 || AMEX == 34))
    {
        printf("AMEX\n");
    }
    //Mastercard
    else if (count == 16 && (MCARD >= 51 && MCARD <= 55))
    {
        printf("MASTERCARD\n");
    }
    //VISA
    else if ((count == 16 && (int)(MCARD / 10) == 4) || (count == 13 && VISA == 4))
        
    {
        printf("VISA\n");
    }
       

    
    
}
