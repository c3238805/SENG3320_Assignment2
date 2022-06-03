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
#include "triangle11.c"
#define BUFFER_SIZE 1024

// this is a c program that will perform Mutation Testing for the Triangle program ( C program).
//this program will take input from MutationTestingInput.txt and use it against the 10 triangle mutants (including the original triangle.c)

//This program will record each round and display the remaining mutants in MutationTestingOutput.txt

//OutputBuffer is used to remove numerical data used to sort each triangle
char outputBuffer[BUFFER_SIZE];

//stores data for the main triangle.c output
char correctOutput[20];

//stores the isosceles string to be used to compare results
char isosceles[] = "isosceles";
//stores the equilateral string to be used to compare results
char equilateral[] = "equilateral";
//used to mark test cases that didn't produce any triangle outcome
char fail[20] = "failed";
// used to store test case results for each triangle
char tests[10][20];
//keeps track of the mutants that are alive
bool mutantAlive[10];



void main()
{
    //resets document for future use
    remove("MutationTestingOutput.txt");
    int aData[17];
    int bData[17];
    int cData[17];
    
    //all mutants designated as alive
    mutantAlive[0] = true;
    mutantAlive[1] = true;
    mutantAlive[2] = true;
    mutantAlive[3] = true;
    mutantAlive[4] = true;
    mutantAlive[5] = true;
    mutantAlive[6] = true;
    mutantAlive[7] = true;
    mutantAlive[8] = true;
    mutantAlive[9] = true;
    FILE *file;
    file = fopen("MutationTestingInput.txt","r");
    if (NULL == file)
    {
        "Input test cases not found \n";
        fclose(file);
        return;
    }
    //scans for three triangle sides to be used in each test case
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
    //main counter for program
    int counter2 = 0;

    //used to store data from triangle console output
    FILE *storageFile;
    while (counter2 != endCount)
    {
    //redirects triangle output to file
    storageFile = freopen("storageFile.txt","w", stdout);
    
    //main triangle test
    printf("1\n");
    triangle(aData[counter2], bData[counter2], cData[counter2]);
   
    //triangle 2 test, if already dead then skip
    if(mutantAlive[0] == true)
    {
      printf("2\n");
    triangle2(aData[counter2], bData[counter2], cData[counter2]);  
    }
    
    //triangle 3 test, if already dead then skip
    if(mutantAlive[1] == true)
    {
    printf("3\n");
    triangle3(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 4 test, if already dead then skip
    if(mutantAlive[2] == true)
    {
    printf("4\n");
    triangle4(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 5 test, if already dead then skip
    if(mutantAlive[3] == true)
    {
    printf("5\n");
    triangle5(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 6 test, if already dead then skip
    if(mutantAlive[4] == true)
    {
    printf("6\n");
    triangle6(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 7 test, if already dead then skip
    if(mutantAlive[5] == true)
    {
    printf("7\n");
    triangle7(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 8 test, if already dead then skip
    if(mutantAlive[6] == true)
    {
    printf("8\n");
    triangle8(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 9 test, if already dead then skip
    if(mutantAlive[7] == true)
    {
    printf("9\n");
    triangle9(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 10 test, if already dead then skip
    if(mutantAlive[8] == true)
    {
    printf("10\n");
    triangle10(aData[counter2], bData[counter2], cData[counter2]);
    }

    //triangle 11 test, if already dead then skip
    if(mutantAlive[9] == true)
    {
    printf("11\n");
    triangle11(aData[counter2], bData[counter2], cData[counter2]);
    }
    //this 0 is used to detect if triangle11 has failed
    printf("0\n");
    //close file
    fclose(stdout);
    //open file as read-only
    storageFile = fopen("storageFile.txt","r");
    //used to remove 1 before triangle.c's results
    fscanf(storageFile,"%s", outputBuffer);
    //store triangle.c result
     fscanf(storageFile,"%s", correctOutput);
     bool correctFailed = false;
        //triangle.c is isosceles, skip next string (which would just be triangle.)
        if (strcmp(correctOutput,isosceles) == 0)
        {
            fscanf(storageFile,"%s", outputBuffer);
        }
        //triangle.c is equilateral, skip next string (which would just be triangle.)
         else if (strcmp(correctOutput,equilateral) == 0)
        {
            fscanf(storageFile,"%s", outputBuffer);
        }
        //triangle.c did not have any output, so the number for the next triangle mutant has been stored instead
       else if (correctOutput[0] >= '0' && correctOutput[0] <= '9')
        {
            //designate triangle as failed
            strcpy(correctOutput, fail);
            //raise flag
             correctFailed = true;
            
        }
     counter = 0;
     
    do 
    {
        //checks if current mutant is alive before working
        if (mutantAlive[counter] == true)
        {
            //previous case failed, skip next string (which would be the number for the next mutant)
        if (correctFailed == false)
            {
            fscanf(storageFile,"%s", outputBuffer);   
            }
            //lower flag
            correctFailed = false;
            //store output results
            fscanf(storageFile,"%s", &tests[counter]);
            //triangle mutant is isosceles, skip next string (which would just be triangle.)
            if (strcmp(tests[counter],isosceles) == 0)
            {
                fscanf(storageFile,"%s", outputBuffer);
            }
            //triangle mutant is equilateral, skip next string (which would just be triangle.)
            else if (strcmp(tests[counter],equilateral) == 0)
            {
                fscanf(storageFile,"%s", outputBuffer);
            }
            //triangle mutant did not have any output, so the number for the next triangle mutant has been stored instead
            else if (tests[counter][0] >= '0' && tests[counter][0] <= '9')
            {
                //designate triangle as failed, raise flag
                strcpy(tests[counter], fail);
                correctFailed = true;
                
            }
            //edge case variant incase somehow the number isn't stored at the front of the string
            else if (tests[counter][1] >= '0' && tests[counter][1] <= '9')
            {
                strcpy(tests[counter], fail);
                
            }        
        }
        
        
        
        //increment counter
        counter++;
    }   while (counter != 10);
    fclose(storageFile);
     

     //store results from round
    FILE *output;

   output = fopen("MutationTestingOutput.txt", "a");
   fprintf(output, "Round: %d\n",counter2);
   fprintf(output, "Test Data: %d %d %d\n",aData[counter2],bData[counter2],cData[counter2]);
   fprintf(output, "Triangle 1: %s\n",correctOutput);
   fprintf(output, "Triangle 2:%s\n Triangle 3:%s\n Triangle 4:%s\n Triangle 5:%s\n Triangle 6:%s\n Triangle 7:%s\n Triangle 8:%s\n Triangle 9:%s\n Triangle 10:%s\n Triangle 11:%s\n \n",tests[0],tests[1],tests[2],tests[3],tests[4],tests[5],tests[6],tests[7],tests[8],tests[9]);
   fclose(output);

     //mutant elimation
    char dead[] = "dead in round ";
    char round = counter2;
    snprintf(dead, 500, "dead in round %d", counter2);

    //if mutant does not have the same results as triangle.c and is still alive, remove from future rounds
    if (strcmp(correctOutput,tests[0]) != 0 && mutantAlive[0] == true)
    {
        mutantAlive[0] = false;
        strcpy(tests[0],dead);
    }

    if (strcmp(correctOutput,tests[1]) != 0 && mutantAlive[1] == true)
    {
        mutantAlive[1] = false;
        strcpy(tests[1],dead);
    }

    if (strcmp(correctOutput,tests[2]) != 0 && mutantAlive[2] == true)
    {
        mutantAlive[2] = false;
        strcpy(tests[2],dead);
    }

    if (strcmp(correctOutput,tests[3]) != 0 && mutantAlive[3] == true)
    {
        mutantAlive[3] = false;
        strcpy(tests[3],dead);
    }

    if (strcmp(correctOutput,tests[4]) != 0 && mutantAlive[4] == true)
    {
        mutantAlive[4] = false;
        strcpy(tests[4],dead);
    }

    if (strcmp(correctOutput,tests[5]) != 0 && mutantAlive[5] == true)
    {
        mutantAlive[5] = false;
        strcpy(tests[5],dead);
    }

    if (strcmp(correctOutput,tests[6]) != 0 && mutantAlive[6] == true)
    {
        mutantAlive[6] = false;
        strcpy(tests[6],dead);
    }

    if (strcmp(correctOutput,tests[7]) != 0 && mutantAlive[7] == true)
    {
        mutantAlive[7] = false;
        strcpy(tests[7],dead);
    }

    if (strcmp(correctOutput,tests[8]) != 0 && mutantAlive[8] == true)
    {
        mutantAlive[8] = false;
        strcpy(tests[8],dead);
    }

    if (strcmp(correctOutput,tests[9]) != 0 && mutantAlive[9] == true)
    {
        mutantAlive[9] = false;
        strcpy(tests[9],dead);
    }
    
    
    counter2++;
    }

    //Final results
    FILE *output;

   output = fopen("MutationTestingOutput.txt", "a");
   fprintf(output, "Final Results\n");
   fprintf(output, "Triangle 1: %s\n",correctOutput);
   fprintf(output, "Triangle 2:%s\n Triangle 3:%s\n Triangle 4:%s\n Triangle 5:%s\n Triangle 6:%s\n Triangle 7:%s\n Triangle 8:%s\n Triangle 9:%s\n Triangle 10:%s\n Triangle 11:%s\n \n",tests[0],tests[1],tests[2],tests[3],tests[4],tests[5],tests[6],tests[7],tests[8],tests[9]);
   fclose(output);
    //removes storage file as it is no longer needed
    remove("storageFile.txt");
}
   