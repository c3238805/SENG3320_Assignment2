//SENG 3320 Assignment 2. Fuzz Testing
//c3238805 Ni Zeng
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "../triangle.c"

#define BUFFER_SIZE 1024

// this is a c program that will perform a Fuzz testing for the Triangle program ( C program).
//this program will take randam input to test triangle (a,b,c)

// this program will record the randam input, output and wherethere have an exception in "FuzzInput_Output.txt" 
int stdoutSave;
char outputBuffer[BUFFER_SIZE];
int i = 0;
int testCase;
int no_non_triangle, no_triangle, no_isosceles_triangle, no_equilateral_triangle = 0;
int outputTestCase;
int OutOfBound=0;


void main()
{
    int testCase;
    printf("Enter number of Test Case of Fuzz: ");
    scanf("%d", &testCase);
    if (testCase == NULL || testCase<0)
    {
        /* File not created hence exit */
        printf("Unable to create Test Case. Exit Program.\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    // Fuzzing loop for entered testCase times
    clock_t begin = clock(); // save begin time while begin to start generate test Case
    while (i <= testCase-1)
    {
        // First generate 3 different randam integer input for a , b, c.
        /*Will return a number between 0 - 9*/
        int a = rand() % 10;
        int b = rand() % 10;
        int c = rand() % 10;

        //set and save next stdout to outputBuffer.
        setvbuf(stdout, outputBuffer, _IOLBF, sizeof(outputBuffer));
        // compute the a, b, c with triangle function
        triangle(a, b, c);
        
        // save a, b,c and outputBuffer value to FuzzInput_Output.txt
        FileManager(a, b, c, outputBuffer);
        
        counter(); // counter record the triangle 

        //fflush(stdout);
        // clear the outputBuffer for next stdout
        
        for (int i = 0; i < sizeof(outputBuffer) ; i ++)
        {
            outputBuffer[i] = NULL;
        }
        setvbuf(stdout, outputBuffer, _IOLBF, sizeof(outputBuffer));
        
        ++ i;
    }
    clock_t end = clock();  // save end time 
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;     // calculate the end time
    // record to .txt & add time spent to .txt
    output(time_spent);

    printf("See Result at Fuzzinput_Output.txt.");
    exit(EXIT_SUCCESS);
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

    // if outputBuffer is empty then there is an error
    if (*outputBuffer != NULL)
    {
        fprintf_s(FuzzInput_Output, "%s", r);
        
    }else {
        // if triangle.c can not output the correct type of triangle,
        
        fprintf_s(FuzzInput_Output, "%s", "\n");
        // keep intput data in record

    }

    /* Close file to save file data */
    fclose(FuzzInput_Output);

    
}

    
    // check if text and pattern match, for counting the number of different triangle
    int match(char outputBuffer[], char pattern[])
    {

        int text_length = strlen(outputBuffer);
        int pattern_length = strlen(pattern);

        if (strlen(outputBuffer) != strlen(pattern))
        {
            return -1;
        }
        else
        {
            for (size_t i = 0; i < text_length; i++)
            {
                if (outputBuffer[i] != pattern[i])
                {
                    return -1;
                }
            }
            return 1;
        }

        }

    // this counter is to record number of different triangle 
    void counter(){
        // once the counter get called, outputTestCase ++;
        outputTestCase ++;

        char non_triangle[] = "non-triangle.\n";
        char triangle[] = "triangle.\n";
        char isosceles_triangle[] = "isosceles triangle.\n";
        char equilateral_triangle[] = "equilateral triangle.\n";

        if (match(outputBuffer, non_triangle) == 1 )
        {
            no_non_triangle++;
        }
        else if (match(outputBuffer, triangle) == 1)
        {
            no_triangle++;

            return;
        }
        else if (match(outputBuffer, isosceles_triangle) == 1)
        {
            no_isosceles_triangle++;
            return;
        }
        else if (match(outputBuffer, equilateral_triangle) == 1)
        {
            no_equilateral_triangle++;
            return;
        }
        else {
            OutOfBound++;
            return;
        }
    }
    void output(double time_spent)
    {
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

        // below is the msg display at the end of the Test Case.
        fprintf_s(FuzzInput_Output, "\nTotal Test case: %d\n", outputTestCase);
        fprintf_s(FuzzInput_Output, "Total time spent: %f s \n", time_spent);
        fprintf_s(FuzzInput_Output, "non_triangle: %d\n", no_non_triangle);
        fprintf_s(FuzzInput_Output, "triangle: %d\n", no_triangle);
        fprintf_s(FuzzInput_Output, "isosceles_triangle: %d\n", no_isosceles_triangle);
        fprintf_s(FuzzInput_Output, "equilateral_triangle: %d\n", no_equilateral_triangle);
        fprintf_s(FuzzInput_Output, "error (with no output triangle type): %d\n", OutOfBound);
        fprintf_s(FuzzInput_Output, "========================================= %s\n", "");

        // here for the errorInput display

        
        fclose(FuzzInput_Output);
    }
