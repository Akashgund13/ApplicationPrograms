import java.util.*;

class Program372
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the string : ");
        String str = sobj.nextLine();

        str = str.replaceAll("\\s+", " ");
        str = str.trim();

        String Arr[] = str.split(" ");
        System.out.println("Number of words are : "+Arr.length);

    }
}