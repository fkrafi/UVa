import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger a, sum, k;
        while(in.hasNext())
        {
            int n = in.nextInt();
            a = in.nextBigInteger();
            sum = a;
            for(int i=2; i<=n; i++)
            {
                k = a.pow(i).multiply(BigInteger.valueOf(i));
                sum = sum.add(k);
            }
            System.out.println(sum);
        }
    }
}