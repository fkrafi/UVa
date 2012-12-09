import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        BigInteger N, a, sum;
        Scanner in = new Scanner(System.in);
        while(in.hasNext())
        {
            N = in.nextBigInteger();
            a = N.add(BigInteger.ONE);
            a = N.multiply(a);
            a = a.divide(BigInteger.valueOf(2));
            sum = a.pow(2);
            System.out.println(sum);
        }
    }
}