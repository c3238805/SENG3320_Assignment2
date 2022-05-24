import java.io.*;
import java.util.*; 


public class KWICTester
{
    public static void main(String args[])
    {
        RandomData.generateRandomData(Math.abs(Integer.parseInt(args[0])), Math.abs(Integer.parseInt(args[1])), Math.abs(Integer.parseInt(args[2])));
        ExceptionHandler eHandler = new ExceptionHandler();
        try
        {        
            String[] pathnames;
            File f1 = new File("InputTextFolder");
            pathnames = f1.list();

            File f2 = new File("ExceptionTextFolder//exceptions.txt");
            f2.createNewFile();
            FileWriter writeFile = new FileWriter(f2, true);

            for(int i = 0; i < Math.abs(Integer.parseInt(args[0])); i++)
            {
                try
                {
                    System.out.println("\n\n" + pathnames[i]);
                    String[] inputText = new String[1];
                    inputText[0] = "InputTextFolder//" + pathnames[i];
                    KWIC tempKWIC = new KWIC();
                    tempKWIC.main(inputText);
                    
                }
                catch(Exception e2) 
                {
                    System.out.println("An error occurred: e2");
                    e2.printStackTrace();  

                    StringWriter sw = new StringWriter();
                    PrintWriter pw = new PrintWriter(sw);
                    e2.printStackTrace(pw);

                    eHandler.addException(sw.toString().replace("\r\n\t"," "), pathnames[i]);
                }

            }
            writeFile.close();
        }
        catch(Exception e1) 
        {
            System.out.println("An error occurred: e1");
            e1.printStackTrace();  
        }

        eHandler.printExceptions();
        
    } 
}
