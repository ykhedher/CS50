#include <string.h>
#include <stdio.h>

int main()
{
    char word[10];
    const char test[10] = "TESt";
    
    printf("give a string: \n");
    scanf("%s", word);
    
    if (!strcasecmp(word, test))
    {
        printf ("success");
        
    }
    else 
    printf("didn't");
}
