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
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    
    if (atoi(argv[1]) > 100 || atoi(argv[1]) < 1)
    {
        printf("The number must be between 1 and 100, inclusive!\n");
        return 2;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    int n = atoi(argv[1]);

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }
    
    int infile_width = bi.biWidth;
    int infile_height = bi.biHeight;
    
    bi.biWidth *= n;
    
    bi.biHeight *= n;
    
    // determine padding for scanlines
    int infile_padding =  (4 - (infile_width * sizeof(RGBTRIPLE)) % 4) % 4;
    // determines padding for the enhanced file
    int outfile_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bf.bfSize = 54 + (bi.biWidth * abs(bi.biHeight)) * 3 + outfile_padding*abs(bi.biHeight);
    
    bi.biSizeImage = bf.bfSize - 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);
    


    // iterate over infile's scanlines
    for (int i = 0; i < abs(infile_height); i++)
    {
        // this iterates over the height
        for (int p =0; p<n; p++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < infile_width; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // this writes triple n times
                for (int q=0; q<n; q++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            // skip over padding, if any
            fseek(inptr, infile_padding, SEEK_CUR);
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < outfile_padding; k++)
                fputc(0x00, outptr);
                
            fseek(inptr, -(infile_width*3+infile_padding), SEEK_CUR);
        }
        fseek(inptr, (infile_width*3+infile_padding), SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}