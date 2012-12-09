import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String args[])
    {
	Scanner in = new Scanner(System.in);
        BigInteger num, two=BigInteger.valueOf(2), n;
        int p;
        BigInteger md = new BigInteger("1000000007");
        p = in.nextInt();
        for(int i=1; i<=p; i++)
        {
            n = in.nextBigInteger();
            num = two.modPow(n.subtract(BigInteger.ONE), md);
            n = n.mod(md);
            num = n.multiply(num);
            num = num.mod(md);
            System.out.println("Case #" + i + ": " + num);
        }
    }
}
