#include <stdio.h>
#include <cs50.h>
#include <math.h>
//prototype of the function
int func(long credit, int count);
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
    long copy = Credit;
    //count how many digits
    while (Credit > 1)
    {
        Credit /= 10;
        count++;
    }
    int isValid = func(copy, count); 
    //INVALID
    if (isValid)     
    {
        printf("INVALID\n");
    }
    //american-express
    else if (count == 15 && (AMEX == 37 || AMEX == 34))
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
    else 
    {
        printf("INVALID\n");
    }
      
}

// function 
int func(long credit, int count)
{ 
    long p = pow(10, count - 1);
    int sum = 0;
    for (int i = 0; i < count; i++)
    {
        // extract the ith digit
        int k = credit / p;
        //if count is not pair
        if (count % 2 != 0)
        {
        // check if the digit is odd or even
            if (i % 2 != 0)
            {
        // if it's higher than 10 exp 12 = 1 + 2
              k*=2;
                if (k > 9)
                {
                    sum += ((int) k / 10) + (k % 10);
                }
                 // if it's not higher than 9 add it to the sum directly
                else sum +=k;
            }
                 // if it's not even add it to the sum without doubling it
            else {
                    sum += k;
                 }
            credit %= p;
            p/=10;   
    
        }
       
        else if (count % 2 ==0)
        {
                 if (i % 2 == 0)
            {
              k*=2;
                if (k > 9)
                {
                    sum += ((int) k / 10) + (k % 10);
                }
                else sum +=k;
            }
            else {
                    sum += k;
                 }
            credit %= p;
            p/=10;   
            }
            
       
    }
     
    if (sum % 10 == 0)
    {
        //return 0 means it's valid
        return 0;
    }
    
            
    else
    {
        //return 1 means it's not valid
        return 1;
    }
        
}


