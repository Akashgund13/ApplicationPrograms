
import java.util.*;

class Digits 
{
    public int CountDigits(int iValue)
    {
        int iDigit = 0;
        int iCount = 0;

        while(iValue != 0)
        {
            iDigit = iValue % 10;
            iCount++;
            iValue = iValue / 10;
        }
        return iCount;
    }
}

class Program336
{
    public static void main(String arg[])
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        int iNo = sobj.nextInt();

        Digits dobj = new Digits();

        int iRet = dobj.CountDigits(iNo);

        System.out.println("Number of digits are : "+iRet);
    }
}