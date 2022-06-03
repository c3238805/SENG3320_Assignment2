// KWICTester.java
// **************************
//
// Written by   : Kyle Beattie c3303374 Group10
// Course       : SENG3320
// Modified     : 03/06/2022
// 
// Program Description: Used to run the KWIC program and obtain all exceptions generated using Fuzz Testing

import java.io.*;
import java.util.*; 


public class KWICTester
{
    public static void main(String args[])
    {
        // Calls the random data generation method for Fuzz Testing
        RandomData.generateRandomData(Math.abs(Integer.parseInt(args[0])), Math.abs(Integer.parseInt(args[1])), Math.abs(Integer.parseInt(args[2])));

        // Creates a new instance of the ExceptionHandler class
        ExceptionHandler eHandler = new ExceptionHandler();
        try
        {        

            // Returns the path names for all input texts generated 
            String[] pathnames;
            File f1 = new File("InputTextFolder");
            pathnames = f1.list();

            // Loops through all the newly generated input text files
            for(int i = 0; i < Math.abs(Integer.parseInt(args[0])); i++)
            {
                try
                {
                    // Creates the path to the input text file
                    System.out.println("\n\n" + pathnames[i]);
                    String[] inputText = new String[1];
                    inputText[0] = "InputTextFolder//" + pathnames[i];

                    // Creates a new instance of the KWIC class and calls the main method with the input text file
                    KWIC tempKWIC = new KWIC();
                    tempKWIC.main(inputText);
                    
                }
                // Catches any exceptions that occur when running the KWIC program
                catch(Exception e2) 
                {
                    // Prints the stack trace to the console
                    System.out.println("An error occurred: e2");
                    e2.printStackTrace();  

                    // Creates a string from the exception stack trace
                    StringWriter sw = new StringWriter();
                    PrintWriter pw = new PrintWriter(sw);
                    e2.printStackTrace(pw);

                    // Attempts to add the exception to the list of occurred exceptions
                    eHandler.addException(sw.toString().replace("\r\n\t"," "), pathnames[i]);
                }
            }

        }
        catch(Exception e1) 
        {
            System.out.println("An error occurred: e1");
            e1.printStackTrace();  
        }

        eHandler.printExceptions();
        
    } 
}
