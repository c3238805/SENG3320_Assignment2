void triangle (int a, int b, int c){
    if ((a+b>c)&&(a+c>b)&&(b+c>a)) {
        if (a==b || a==c || b==c) {
            if (a==c && a==b)
                printf("equilateral triangle .\n");
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

int main(){
    printf("hey there");
    int a,b,c;
	klee_make_symbolic(&a, sizeof(a), "a");
	klee_make_symbolic(&b, sizeof(b), "b");
	klee_make_symbolic(&c, sizeof(c), "c");
  	triangle(a,b,c);
	return 0;
}


/*
    klee output:

        Job queued!

        Executing KLEE

        Executing KLEE

        Uploading KLEE output directory

        Done!

        Ran command "/home/klee/klee_build/bin/klee /tmp/code/code.o".

        KLEE: output directory is "/tmp/code/klee-out-0"
        KLEE: Using STP solver backend
        KLEE: WARNING: undefined reference to function: printf
        KLEE: WARNING ONCE: calling external: printf(26363296) at /tmp/code/code.c:19 9
        hey therenon-triangle.
        non-triangle.
        non-triangle.
        equilateral triangle .
        triangle.
        isosceles triangle.
        isosceles triangle.

        KLEE: done: total instructions = 137
        KLEE: done: completed paths = 8
        KLEE: done: generated tests = 8
    Stats:
        Name 	    Value
        Instrs 	    137
        Time(s) 	0.2693427
        ICov(%) 	100
        BCov(%) 	100
        ICount 	    84
        TSolver(%) 	89.75294299789823
*/