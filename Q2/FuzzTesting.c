#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "triangle.c"

#define BUFFER_SIZE 1024

// this is a c program that will perform a Fuzz testing for the Triangle program ( C program).
//this program will take randam input to test triangle (a,b,c)

// this program will record the randam input, output and wherethere have an exception in "FuzzInput_Output.txt" 
int stdoutSave;
char outputBuffer[BUFFER_SIZE];
int i = 0;
int no_non_triangle, no_triangle, no_isosceles_triangle, no_equilateral_triangle = 0;
int OutOfBound=0;
void main()
{
    srand(time(NULL));
    // Fuzzing loop for 50 times 
    while (i<=50)
    {
        // First generate 3 different randam integer input for a , b, c.
        
        int a = rand();
        int b = rand();
        int c = rand();

        setvbuf(stdout, outputBuffer, _IOFBF, BUFFER_SIZE);
        // compute the a, b, c with triangle function
        triangle(a, b, c);
        
        // save a, b,c value to FuzzInput_Output.txt
        FileManager(a, b, c, outputBuffer);

        setvbuf(stdout, NULL, _IONBF, BUFFER_SIZE);

        counter();  // counter 
        ++ i;
    }

    // add final counter record to .txt
    output();

    // check if any exception and save exception in "FuzzException.txt"
}

void FileManager(int a, int b, int c, char r[BUFFER_SIZE])
{
    // this file manage is to create "FuzzInput_Output.txt" if not exist.
    // this void function also control input and output of the fuzz testing.

    char *filename = "FuzzInput_Output.txt";
    FILE *FuzzInput_Output = fopen(filename, "r");

    if (FuzzInput_Output == NULL)
    {
        /* if file not exist , crate a new one */
        FuzzInput_Output = fopen(filename, "w");
        /* fopen() return NULL if last operation was unsuccessful */
        if (FuzzInput_Output == NULL)
        {
            /* File not created hence exit */
            printf("Unable to create file.\n");
            exit(EXIT_FAILURE);
        }

    }else {
        FuzzInput_Output = fopen(filename, "a");
    }

    
  
    fprintf_s(FuzzInput_Output, "%d  ", a);
    fprintf_s(FuzzInput_Output, "%d  ", b);
    fprintf_s(FuzzInput_Output, "%d  ", c);
    fprintf_s(FuzzInput_Output, "%s", r);

    /* Close file to save file data */
    fclose(FuzzInput_Output);

    
}

    
// check if text and pattern match
    int match(char text[], char pattern[])
    {
        int c, d, e, text_length, pattern_length, position = -1;

        text_length = strlen(text);
        pattern_length = strlen(pattern);

        if (pattern_length > text_length)
        {
            return -1;
        }

        for (c = 0; c <= text_length - pattern_length; c++)
        {
            position = e = c;

            for (d = 0; d < pattern_length; d++)
            {
                if (pattern[d] == text[e])
                {
                    e++;
                }
                else
                {
                    break;
                }
            }
            if (d == pattern_length)
            {
                return position;
            }
        }

        return -1;
    }


    // this counter is to record number of different triangle 
    void counter(){

        char non_triangle[] = "non-triangle.";
        char triangle[] = "triangle.";
        char isosceles_triangle[] = "isosceles triangle.";
        char equilateral_triangle[] = "equilateral triangle.";

        if (match(outputBuffer, non_triangle))
        {
            no_non_triangle++;
        }
        else if (match(outputBuffer, triangle))
        {
            no_triangle++;

            return;
        }
        else if (match(outputBuffer, isosceles_triangle))
        {
            no_isosceles_triangle++;
            return;
        }
        else if (match(outputBuffer, equilateral_triangle))
        {
            no_equilateral_triangle++;
            return;
        }
        else {
            OutOfBound++;
            return;
        }
    }
    void output(){
        char *filename = "FuzzInput_Output.txt";
        FILE *FuzzInput_Output = fopen(filename, "r");

        if (FuzzInput_Output == NULL)
        {
            /* if file not exist , crate a new one */
            FuzzInput_Output = fopen(filename, "w");
            /* fopen() return NULL if last operation was unsuccessful */
            if (FuzzInput_Output == NULL)
            {
                /* File not created hence exit */
                printf("Unable to create file.\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            FuzzInput_Output = fopen(filename, "a");
        }

        fprintf_s(FuzzInput_Output, "non_triangle: %d\n", no_non_triangle);
        fprintf_s(FuzzInput_Output, "triangle: %d\n", no_triangle);
        fprintf_s(FuzzInput_Output, "isosceles_triangle: %d\n", no_isosceles_triangle);
        fprintf_s(FuzzInput_Output, "equilateral_triangle: %d\n", no_equilateral_triangle);
        fclose(FuzzInput_Output);
    }