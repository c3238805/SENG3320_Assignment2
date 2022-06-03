// KWICTester.java
// **************************
//
// Written by   : Kyle Beattie c3303374 Group10
// Course       : SENG3320
// Modified     : 03/06/2022
// 
// Program Description: Generates the random data required for Fuzz Testing based on the inputs arguments 

import java.io.*;
import java.util.Random;
 
public class RandomData
{
   public static void generateRandomData(int numberOfFiles, int maxLines, int maxCharacter)
   {     
      Random rand = new Random();

      int lines;
      int numberOfCharacters;
      String lineString;

      // Loops for the intended number of files wanting to be creates
      for (int i = 1; i <= numberOfFiles; i++) 
      {
         // Determines how many lines of books names this file will contain
         lines = rand.nextInt(maxLines) + 1;  
         
         try
         {
            // Creates the input text file
            File inputText = new File(String.format("InputTextFolder//inputText" +"%05d" +".txt",i));
            inputText.createNewFile();
            FileWriter writeFile = new FileWriter(inputText, false);

            // Loops through each line of the creates file
            for(int j = 0; j < lines; j++)
            {
               // Determines how many characters the book title will contain
               numberOfCharacters = rand.nextInt(maxCharacter) + 1;

               // Calls the generateString method with the number of characters to contain
               lineString = generateString(numberOfCharacters);

               // Writes the line to the text file
               writeFile.write(lineString);
            }

            writeFile.close();
         }
         catch(Exception e)
         {
            System.out.println("An error occurred: e");
            e.printStackTrace();
         }

      }
   }

   private static String generateString(int characters)
   {

      Random rand = new Random();
      int asciiNumber;
      String lineString = "";

      // Loops through the required number of characters 
      for(int i = 0; i < characters; i++)
      {     
         // Randomly selects a number corresponding to an ASCII character 
         asciiNumber = rand.nextInt(107) + 20;

         // Sets value less than a space to a space character increasing the weight for a space to appear
         if(asciiNumber < 32)
         {
            asciiNumber = 32;
         }

         // Adds the character to the string
         lineString += Character.toString(asciiNumber);
      }

      return lineString + "\n";
   }
}
