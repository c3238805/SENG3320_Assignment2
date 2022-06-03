// KWICTester.java
// **************************
//
// Written by   : Kyle Beattie c3303374 Group10
// Course       : SENG3320
// Modified     : 03/06/2022
// 
// Program Description: Handles the exceptions generated from the KWIC program so that only unique exceptions are stored and printed 

import java.io.*;
import java.util.*;

public class ExceptionHandler
{
   Set<String> exceptionSet;
   Set<String> subStringSet;
   List<String> inputSet;

   public ExceptionHandler()
   {
      // Holds the entire exception string
      exceptionSet = new LinkedHashSet<String>();

      // Holds the exception values after the first "at"
      subStringSet = new LinkedHashSet<String>();

      // Holds the name of the input file that caused the exception
      inputSet = new LinkedList<String>();
   }

   public void addException(String exception, String inputText)
   {
      // Checks if the exception contains "at"
      if(exception.contains("at"))
      {
         // Splits the exception string at the first index of "at"
         String exceptionSubString = exception.substring(exception.indexOf("at"));

         // Checks if the exception message after the at is already present so only unique exceptions are stored
         if(subStringSet.add(exceptionSubString))
         {
            // Double checks if the entire exception message has been saved
            if(exceptionSet.add(exception))
            {
               // Adds the input text file name
               inputSet.add(inputText); 
            }
         }
      }     
   }

   public void printExceptions()
   {
      try
      {
         // Creates a new exceptions.txt file to contain the exception information
         File f2 = new File("ExceptionTextFolder//exceptions.txt");
         f2.createNewFile();
         FileWriter writeFile = new FileWriter(f2, false);

         // Creates an iterator for the input and exception sets
         Iterator<String> inputIterator = inputSet.iterator();
         Iterator<String> exceptionIterator = exceptionSet.iterator();

         int i = 0;

         writeFile.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r");

         // Loops through until all exceptions have been finished printing to the exception text file
         while(inputIterator.hasNext() && exceptionIterator.hasNext())
         {
            // Retrieves the exception information 
            String inputText = inputIterator.next();
            String exception = exceptionIterator.next();

            // Counts the number of unique exceptions
            i++;

            // Writes each line of the input text file associated with the caught exception to the exceptions.txt file
            File inputFile = new File("InputTextFolder//" + inputText);
            Scanner myScanner = new Scanner(inputFile);
            writeFile.write("Input: " + inputText + "\r");
            
            while(myScanner.hasNextLine())
            {
               writeFile.write(myScanner.nextLine() + "\r");
            }

            myScanner.close();

            // Writes the exception caught to the exceptions.txt file
            writeFile.write("\rException: \r" + exception);
            writeFile.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r");
         }

         // Writes the number of unique exceptions generated from Fuzz Testing
         writeFile.write("Unique Exceptions: " + i);
         writeFile.close();

         System.out.println("\nUnique Exceptions: " + i);

      }
      catch (Exception e3) 
      {
         System.out.println("An error occurred: e3");
         e3.printStackTrace();  
      }
   }



}
