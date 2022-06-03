//SENG 3320 Assignment 2. Mutation Testing
//c3356468 Austin Baxter
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "triangle.c"
#include "triangle2.c"
#include "triangle3.c"
#include "triangle4.c"
#include "triangle5.c"
#include "triangle6.c"
#include "triangle7.c"
#include "triangle8.c"
#include "triangle9.c"
#include "triangle10.c"
#define BUFFER_SIZE 1024

// this is a c program that will perform a Fuzz testing for the Triangle program ( C program).
//this program will take randam input to test triangle (a,b,c)

// this program will record the randam input, output and wherethere have an exception in "FuzzInput_Output.txt" 
char outputBuffer[BUFFER_SIZE];
char correctOutput[20];
char isosceles[] = "isosceles";
char equilateral[] = "equilateral";
char fail[20] = "failed";
char tests[9][20];
bool mutantAlive[9];
int mutantsAlive = 9;


void main()
{
    remove("MutationTestingOutput.txt");
    int aData[17];
    int bData[17];
    int cData[17];
    
    mutantAlive[0] = true;
    mutantAlive[1] = true;
    mutantAlive[2] = true;
    mutantAlive[3] = true;
    mutantAlive[4] = true;
    mutantAlive[5] = true;
    mutantAlive[6] = true;
    mutantAlive[7] = true;
    mutantAlive[8] = true;
    FILE *file;
    file = fopen("MutationTestingInput.txt","r");
    if (NULL == file)
    {
        "Input test cases not found \n";
        fclose(file);
        return;
    }
    int endCount = 17;
    int counter = 0;
    do 
    {
        fscanf(file,"%d", &aData[counter]);
        

        fscanf(file,"%d", &bData[counter]);
        

        fscanf(file,"%d", &cData[counter]);
        
        
        counter++;
    }   while (counter != endCount);
    fclose(file);
    
    int counter2 = 0;
    char mainOutput[20];


    FILE *storageFile;
    while (counter2 != endCount)
    {
    
    storageFile = freopen("storageFile.txt","w", stdout);
    
    printf("1\n");
    triangle(aData[counter2], bData[counter2], cData[counter2]);
   
    if(mutantAlive[0] == true)
    {
      printf("2\n");
    triangle2(aData[counter2], bData[counter2], cData[counter2]);  
    }
    
    
    if(mutantAlive[1] == true)
    {
    printf("3\n");
    triangle3(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[2] == true)
    {
    printf("4\n");
    triangle4(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[3] == true)
    {
    printf("5\n");
    triangle5(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[4] == true)
    {
    printf("6\n");
    triangle6(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[5] == true)
    {
    printf("7\n");
    triangle7(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[6] == true)
    {
    printf("8\n");
    triangle8(aData[counter2], bData[counter2], cData[counter2]);
    }

    if(mutantAlive[7] == true)
    {
    printf("9\n");
    triangle9(aData[counter2], bData[counter2], cData[counter2]);
    }
    if(mutantAlive[8] == true)
    {
    printf("0\n");
    triangle10(aData[counter2], bData[counter2], cData[counter2]);
    }
    printf("0\n");
    
    fclose(stdout);
    
    storageFile = fopen("storageFile.txt","r");
    fscanf(storageFile,"%s", outputBuffer);
     fscanf(storageFile,"%s", correctOutput);
     bool correctFailed = false;
     
        if (strcmp(correctOutput,isosceles) == 0)
        {
            fscanf(storageFile,"%s", outputBuffer);
        }
         else if (strcmp(correctOutput,equilateral) == 0)
        {
            fscanf(storageFile,"%s", outputBuffer);
        }
       else if (correctOutput[0] >= '0' && correctOutput[0] <= '9')
        {
            strcpy(correctOutput, fail);
            
             correctFailed = true;
            
        }
     counter = 0;
     
    do 
    {
        if (mutantAlive[counter] == true)
        {
        if (correctFailed == false)
            {
            fscanf(storageFile,"%s", outputBuffer);   
            }
            correctFailed = false;
            fscanf(storageFile,"%s", &tests[counter]);
            if (strcmp(tests[counter],isosceles) == 0)
            {
                fscanf(storageFile,"%s", outputBuffer);
            }
            else if (strcmp(tests[counter],equilateral) == 0)
            {
                fscanf(storageFile,"%s", outputBuffer);
            }
            else if (tests[counter][0] >= '0' && tests[counter][0] <= '9')
            {

                strcpy(tests[counter], fail);
                correctFailed = true;
                
            }
            else if (tests[counter][1] >= '0' && tests[counter][1] <= '9')
            {
                strcpy(tests[counter], fail);
                
            }        
        }
        else 
        {
          //strcpy(tests[counter], "dead");  
        }
        
        
        
        
        counter++;
    }   while (counter != 9);
    fclose(storageFile);
     
    char dead[] = "dead in round ";
    char round = counter2;
    snprintf(dead, 500, "dead in round %d", counter2);
    if (strcmp(correctOutput,tests[0]) != 0 && mutantAlive[0] == true)
    {
        mutantAlive[0] = false;
        mutantsAlive--;
        strcpy(tests[0],dead);
    }

    if (strcmp(correctOutput,tests[1]) != 0 && mutantAlive[1] == true)
    {
        mutantAlive[1] = false;
        mutantsAlive--;
        strcpy(tests[1],dead);
    }

    if (strcmp(correctOutput,tests[2]) != 0 && mutantAlive[2] == true)
    {
        mutantAlive[2] = false;
        mutantsAlive--;
        strcpy(tests[2],dead);
    }

    if (strcmp(correctOutput,tests[3]) != 0 && mutantAlive[3] == true)
    {
        mutantAlive[3] = false;
        mutantsAlive--;
        strcpy(tests[3],dead);
    }

    if (strcmp(correctOutput,tests[4]) != 0 && mutantAlive[4] == true)
    {
        mutantAlive[4] = false;
        mutantsAlive--;
        strcpy(tests[4],dead);
    }

    if (strcmp(correctOutput,tests[5]) != 0 && mutantAlive[5] == true)
    {
        mutantAlive[5] = false;
        mutantsAlive--;
        strcpy(tests[5],dead);
    }

    if (strcmp(correctOutput,tests[6]) != 0 && mutantAlive[6] == true)
    {
        mutantAlive[6] = false;
        mutantsAlive--;
        
        strcpy(tests[6],dead);
    }

    if (strcmp(correctOutput,tests[7]) != 0 && mutantAlive[7] == true)
    {
        mutantAlive[7] = false;
        mutantsAlive--;
        strcpy(tests[7],dead);
    }

    if (strcmp(correctOutput,tests[8]) != 0 && mutantAlive[8] == true)
    {
        mutantAlive[8] = false;
        mutantsAlive--;
        strcpy(tests[8],dead);
    }
    
    FILE *output;

   output = fopen("MutationTestingOutput.txt", "a");
   fprintf(output, "Round: %d\n",counter2);
   fprintf(output, "Test Data: %d %d %d\n",aData[counter2],bData[counter2],cData[counter2]);
   fprintf(output, "Triangle 1: %s\n",correctOutput);
   fprintf(output, "Triangle 2:%s\n Triangle 3:%s\n Triangle 4:%s\n Triangle 5:%s\n Triangle 6:%s\n Triangle 7:%s\n Triangle 8:%s\n Triangle 9:%s\n Triangle 10:%s\n \n",tests[0],tests[1],tests[2],tests[3],tests[4],tests[5],tests[6],tests[7],tests[8],tests[9]);
   fclose(output);
    counter2++;
    }
    remove("storageFile.txt");
}
   