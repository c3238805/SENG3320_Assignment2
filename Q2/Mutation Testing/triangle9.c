#include <stdio.h>


void triangle9 (int a, int b, int c){ 
if ((a+b>c)&&(a+c>b)&&(b+c>a)) { 
    if (a==b || a!=c || b==c) { 
        if (a==c && a==b) 
            printf("equilateral triangle.\n"); 
        else if (a==c||b==c) 
            printf("isosceles triangle.\n"); 
    } 
    else 
         printf("triangle.\n"); 
} 
else 
    printf("non-triangle.\n"); 
  
return; 
} 