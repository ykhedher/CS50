#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int notDigit(string argv);
string shift(string text, int key);


int main(int argc, string argv[])
{
    // case the number of arguments is not 2 
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
      
    }          
    // case the number of arguments is 2 and arg 2 is string or number + characters
    else if (notDigit(argv[1]))
    {
        printf("Usage: ./caesar key\n");
    }
    //case all is Good
    else
    {
        int key = atoi(argv[1]);
        if (key < 1)
        {
            printf("Usage: ./caesar key\n");
        }
        else
        {
            //prompt the user for a string
            string plaintext = get_string("plaintext: ");
            //output the encrypted message
            printf("ciphertext: %s\n", shift(plaintext, key));
        }


    }
    

             
        
         
}
     


//check if the argument n2 is only digits
int notDigit(string argv)
{
    int length = strlen(argv), i;
    for (i = 0; i < length; i++)
    {
        if (isdigit(argv[i]) == 0)
        {
            return 1;
        }
    }  
    return 0;          
}
//shift function
string shift(string text, int key)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // check if it's an alphabet
        if (isalpha(text[i]))
        {
            //check if it's an uppercase
            if (isupper(text[i]))
            {
                text[i] = (((text[i] - 'A') + key) % 26) + 'A';
            }
            //if it's not an uppercase
            else
            {
                text[i] = (((text[i] - 'a') + key) % 26) + 'a';
            }
            
        }
        
    }
    return text;
}



