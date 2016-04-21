/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./copy input output\n");
        return 1;
    }

    // remember filenames
    char* input = argv[1];
    char* output = argv[2];

    // open input file 
    FILE* input_file = fopen(input, "r");
    if (input_file == NULL)
    {
        printf("Could not open %s.\n", input);
        return 2;
    }

    // open output file
    FILE* output_file = fopen(output, "w");
    if (output_file == NULL)
    {
        fclose(input_file);
        fprintf(stderr, "Could not create %s.\n", output);
        return 3;
    }

    // read input's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, input_file);

    // read input's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, input_file);

    // ensure input is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(output_file);
        fclose(input_file);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write output's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, output_file);

    // write output's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, output_file);

    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over input's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from input
            fread(&triple, sizeof(RGBTRIPLE), 1, input_file);
                
            if (triple.rgbtRed > 0xf0 && triple.rgbtBlue == 0x00 && triple.rgbtGreen == 0x00)
            {
                triple.rgbtRed = 0xff;
                triple.rgbtBlue = 0xff;
                triple.rgbtGreen = 0xff;
            }
            
            // write RGB triple to output
            fwrite(&triple, sizeof(RGBTRIPLE), 1, output_file);
        }

        // skip over padding, if any
        fseek(input_file, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, output_file);
        }
    }

    // close input
    fclose(input_file);

    // close output
    fclose(output_file);

    // that's all folks
    return 0;
}


// #include <stdio.h>
// #include <cs50.h>
// #include <stdlib.h>

// int main(int argc, char* argv[])
// {
//     if (argc!=3)
//     {
//         printf("Usage: %s input output", argv[0]);
//         return 1;
//     }
    
//     char* input = argv[1];
//     char* output = argv[2];
    
//     FILE* input_file = fopen(input, "r");
//     if (input_file == NULL)
//         return 2;
    
//     FILE* output_file = fopen(output, "w");
//     if (output_file == NULL)
//     {
//         fclose(input_file);
//         return 3;
//     }
    
    
    
//     fclose(input_file);
//     fclose(output_file);
    
// }