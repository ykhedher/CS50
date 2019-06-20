#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    //remember file name
    char *infile = argv[1];
    //open inputfile
    FILE *inptr = fopen(infile, "r");
    
    if (inptr == NULL)
    {
        fprintf(stderr, "can not open %s .\n", infile);
        return 2;
    }
    
    // Initialize JPG identification search buffer to size of read in chunks
    // Using 'unsigned' for 0 to 255
    unsigned char data[512];
    
    // Initialize tracker variables
    int jpgCounter = 0;
    int openFile = 0;
    // Initialize file name and img_file
    FILE *img;
    char filename[10];
    // Loop through reading 512 byte blocks of image file till you get to end of the file
    // ...Using fread's return value to designate if a complete block was returned or failed... eg EOF reached
    // ...Using while loop's expression boolean returning false to end the looping at EOF
    while (fread(&data, 512, 1, inptr))
    {
        //identifying JPEG
        if (data[0] == 0xff && 
            data[1] == 0xd8 && 
            (data[3] & 0xf0) == 0xe0)
        // Yes...this is the start of a new JPEG
        {
            
            // Do we already have a JPEG file open?
            // If we have an open file
            if (openFile)
            {
                fclose(img);
                openFile = 0;
                //create a file name
                sprintf(filename, "%03i.jpg", jpgCounter);
                //open a new file 
                img = fopen(filename, "a");
                openFile = 1;
                jpgCounter++;
            }
            // If we do NOT have an open file
            if (!openFile)
            {
                sprintf(filename, "%03i.jpg", jpgCounter);
                img = fopen(filename, "w");
                openFile = 1;
                jpgCounter++;
            }
            
            // write the buffer to the file
            fwrite(&data, 512, 1, img);
        }
        // No...this is not the start of a new JPEG
        else
        {
            if (openFile)
            {
                fwrite(&data, 512, 1, img);
            }
            if (!openFile)
            {
                //DOES NOTHING
            }
        }
    }
    fclose(inptr);
    // close any open jpeg file
    fclose(img);

}


