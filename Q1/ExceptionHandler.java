import java.io.*;
import java.util.*;

public class ExceptionHandler
{
   Set<String> exceptionSet;
   Set<String> subStringSet;
   List<String> inputSet;

   public ExceptionHandler()
   {
      exceptionSet = new LinkedHashSet<String>();
      subStringSet = new LinkedHashSet<String>();
      inputSet = new LinkedList<String>();
   }

   public void addException(String exception, String inputText)
   {
      if(exception.contains("at"))
      {
         String exceptionSubString = exception.substring(exception.indexOf("at"));
         if(subStringSet.add(exceptionSubString))
         {
            if(exceptionSet.add(exception))
            {
               inputSet.add(inputText); 
            }
         }
      }
      else
      {
         if(exceptionSet.add(exception))
         {
            inputSet.add(inputText); 
         }
      }
      
   }

   public void printExceptions()
   {
      try
      {
         File f2 = new File("ExceptionTextFolder//exceptions.txt");
         f2.createNewFile();
         FileWriter writeFile = new FileWriter(f2, false);

         Iterator<String> inputIterator = inputSet.iterator();
         Iterator<String> exceptionIterator = exceptionSet.iterator();

         int i = 0;

         writeFile.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r");
         while(inputIterator.hasNext() && exceptionIterator.hasNext())
         {
            String inputText = inputIterator.next();
            String exception = exceptionIterator.next();
            i++;

            File inputFile = new File("InputTextFolder//" + inputText);
            Scanner myScanner = new Scanner(inputFile);

            writeFile.write("Input: " + inputText + "\r");
            
            while(myScanner.hasNextLine())
            {
               writeFile.write(myScanner.nextLine() + "\r");
            }

            myScanner.close();

            writeFile.write("\rException: \r" + exception);
            writeFile.write("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r");

            File inputTextFile = new File("InputTextFolder//" + inputText);
         }
         writeFile.write("Unique Exceptions: " + i);

         writeFile.close();

      }
      catch (Exception e3) 
      {
         System.out.println("An error occurred: e3");
         e3.printStackTrace();  
      }

      
   }

}
