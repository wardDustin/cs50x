/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

void getPics(void);

void close(void);

//files are global to use easily with functions
//inptr is to store the memory card contents
FILE* inptr = NULL;
//newfile will store the inptr's data
FILE* newfile = NULL;

int main(void)
{
    inptr = fopen("card.raw", "r");
    if (inptr==NULL)
    {
        printf("card.raw is not opening\n");
        return 1;
    }
    //recover the pictures
    getPics();
    //close the files
    close();
}

void getPics(void)
{
    unsigned char buffer[512];
    int jpgnumber = 0;
    char temp[8];
    
    while (!feof(inptr))
    {
        //reads from inptr to store in array buffer    
        if(fread(buffer, sizeof(buffer), 1, inptr)!=1)
            break;
        
        if (buffer[0] == 0xff && buffer[1]==0xd8 && buffer[2] == 0xff && (buffer[3]>=0xe0 && buffer[3]<=0xef))
        {
            if (newfile!=NULL)
                fclose(newfile);
            
            //sprintf creates a formatted string each time that this loops executes, tied to jpgnumber and stored in the array temp
            sprintf(temp, "%03d.jpg", jpgnumber);
            
            //counts how many times a jpeg is created... ties to  sprintf to name the file
            jpgnumber++;
            
            //opens a file named by temp that can be written
            newfile = fopen(temp, "w");
            
            //writes into newfile, the data from buffer
            fwrite(buffer, sizeof(buffer), 1, newfile);
        }
        else if (jpgnumber>0)
        {
            /* if the first 4 bytes don't match jpeg, then it is either before the jpegs start OR inbetween bytes
             * if jpgnumber is zero, than no jpegs have been found, so the loop should be continues
             * else the bytes are between jpeg headers and need to be writen to the buffer */
            fwrite(buffer, sizeof(buffer), 1, newfile);
        }
    }
}

void close(void)
{
    //closes both files
    fclose(newfile);
    fclose(inptr);
}