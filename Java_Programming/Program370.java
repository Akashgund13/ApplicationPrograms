import java.util.*;

class Program370
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string : ");
        String str = sobj.nextLine();

        System.out.println(str.length());
        
        str = str.replaceAll("\\s+", " ");
        str = str.trim();

        int iFrequency = 0;

        for(int iCnt = 0; iCnt < str.length(); iCnt++)
        {
            if(str.charAt(iCnt) == ' ')
            {
                iFrequency++;
            }
        }

        System.out.println("Number of words are :"+ (iFrequency + 1));

    }
}