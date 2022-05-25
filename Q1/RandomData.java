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

      for (int i = 1; i <= numberOfFiles; i++) 
      {
         lines = rand.nextInt(maxLines) + 1;  
         
         try
         {
            File inputText = new File(String.format("InputTextFolder//inputText" +"%05d" +".txt",i));
            inputText.createNewFile();

            FileWriter writeFile = new FileWriter(inputText, false);

            for(int j = 0; j < lines; j++)
            {
               numberOfCharacters = rand.nextInt(maxCharacter) + 1;
               lineString = generateString(numberOfCharacters);
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

      for(int i = 0; i < characters; i++)
      {
         asciiNumber = rand.nextInt(107) + 20;
         if(asciiNumber < 32)
         {
            asciiNumber = 32;
         }
         lineString += Character.toString(asciiNumber);
      }

      return lineString + "\n";
   }
}
