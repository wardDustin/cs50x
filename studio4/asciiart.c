#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    //Prompt the user for an input file
    printf("Can I get an input file, please: ");
    char* input = GetString();
    
    //Prompt the user for an output file
    printf("\nCan I get an output file, too: ");
    char* output = GetString();
    
    //Open the file to read from
    FILE* input_file = fopen(input, "r");
    if (input_file==NULL)
        return 1;
        
    //Open output file to write to
    FILE* output_file = fopen(output, "w");
        if (output_file==NULL)
        {
            fclose(input_file);
            return 2;
        }
    
    //allocate memory to store input_file's integers
    char* filesize = malloc(sizeof(int)*256);
    
    //makes a struct variable to access the return value of the struct
    csvLine final;
    
    //gets integers from .csv and prints out #'s instead of numbers and spaces before the hashes
    while(fgets(filesize, sizeof(int)*256, input_file) != NULL)
    {
        final = extractNumbers(filesize);
        int j=0;
        
        if (final.length>1)
        {
            for (int i=0; i<final.length; i++)
            {
                while(j<final.hashLocations[i])
                {
                    fputs(" ", output_file);
                    j++;
                }
                
                fputs("#", output_file);
                j++;
            }
            fputs("\n", output_file);
        }
    }
    
    free(filesize);
    //Close both files
    fclose(input_file);
    fclose(output_file);
    
    printf("Done! If you open up %s you should now see a cool image!\n", output);
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count+1;
    return result;
}