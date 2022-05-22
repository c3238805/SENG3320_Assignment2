#include <time.h>
#include <stdlib.h>
#include "triangle.c"
#include "FileManager.c"
// this is a c program that will perform a Fuzz testing for the Triangle program ( C program).
//this program will take randam input to test triangle (a,b,c)

// this program will record the randam input, output and wherethere have an exception in "FuzzInput_Output.txt" ,  any exception will record in "FuzzException.txt"

void main(){

    //First generate 3 different randam integer input for a , b, c.
    srand(time(NULL));
    int a = rand();
    int b = rand();
    int c = rand();

    // compute the a, b, c with triangle function    
        triangle(a, b, c);
    // save a, b,c value to FuzzInput_Output.txt
        FileManager(a,b,c);
    


    // check if any exception and save exception in "FuzzException.txt"

    
}

