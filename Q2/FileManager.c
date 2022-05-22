void FileManager(int a, int b, int c)
{
    // this file manage is to create "FuzzInput_Output.txt" if not exist.
    // this void function also control input and output of the fuzz testing.

    char *filename = "FuzzInput_Output.txt";
    FILE *fPtr;

    if (!fopen(filename, "r"))
    {
        /* File pointer to hold reference to our file */
        fPtr = fopen(filename, "w");
    }

    /* fopen() return NULL if last operation was unsuccessful */
    if (fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    // int a,b,c to Char
    char input_a = a + '0';
    char input_b = b + '0';
    char input_c = c + '0';
    /* Write data to file */
    fputs("test", fPtr);

    /* Close file to save file data */
    fclose(fPtr);

    /* Success message */
    printf("File created and saved successfully. :) \n");
    return;
}