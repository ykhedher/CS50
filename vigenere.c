#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int notDigit(string argv);
char shift(char text, int key);
int keyDecoding(int c);
int keywordCheck(string text);



int main(int argc, string argv[])
{
    // case the number of arguments is not 2 
    if (argc != 2)
    {
        //printf("Usage: ./caesar key\n");
        printf("Usage: ./vigenere keyword\n");
        

    }          
    // case the number of arguments is 2 and arg 2 is string or number + characters
    else if (keywordCheck(argv[1]))
    {
        printf("Usage: ./vigenere keyword\n");
        EXIT_FAILURE ;
    }
    //case all is Good
    else
    {
        int keywordLength = strlen(argv[1]);
        //prompt the user for a string
        string plaintext = get_string("plaintext: ");
        int plaintextLength = strlen(plaintext);
        //case 1 keywordLength == plaintextLength
        if (keywordLength == plaintextLength)
        {    
            int j = 0;
            for (int i = 0; i < plaintextLength; i++)
            {
                //decode the first key from the first letter
                if (isalpha(plaintext[i]))
                {
                    int key = keyDecoding(argv[1][j]);
                    plaintext[i] = shift(plaintext[i], key);
                    j++;
                        
                }
                   
            }
            //output the encrypted string
            printf("ciphertext: %s\n", plaintext);
        }
        //case 1 keywordLength < plaintextLength
        //if(keywordLength < plaintextLength)
        else 
        {
            int j = 0;
            for (int i = 0; i < plaintextLength; i++)
            {
                if (isalpha(plaintext[i]))
                {
                    
                    //get the key
                    int key = keyDecoding(argv[1][j]);
                    //change the letter correspond to the key
                    plaintext[i] = shift(plaintext[i], key);
                    j++;
                    //if keyword finished back to first letter
                    if (j == keywordLength)
                    {
                        j = 0;
                    }
                }  
            }
            //output the encrypted string
            printf("ciphertext: %s\n", plaintext);
        }
    }
}



//check if the argument number 2 is only digits
int notDigit(string argv)
{
    int length = strlen(argv), i;
    for (i = 0; i < length; i++)
    {
        if (isdigit(argv[i]) == 0)
        {
            return 0;
        }
    }  
    return 1;          
}
//shift function
char shift(char text, int key)
{       
    // check if it's an alphabet
    if (isalpha(text))
    {
        //check if it's an uppercase
        if (isupper(text))
        {
            text = (((text - 'A') + key) % 26) + 'A';
        }
        //if it's not an uppercase
        else
        {
            text = (((text - 'a') + key) % 26) + 'a';
        }

    }
    return text;
}
//key Decoding function
int keyDecoding(int c)
{
    c = toupper(c);
    int key = c - 'A';
    return (key);
}
int keywordCheck (string text)
{
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isdigit(text[i]))
        {
            return 1;
        }
    }
    return 0;
    
}
