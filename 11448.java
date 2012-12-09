import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        int t;
        BigInteger a, b, c;
        Scanner in = new Scanner(System.in);
        t = in.nextInt();
        while(t>0)
        {
            t--;
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            c = a.subtract(b);
            System.out.println(c);
        }
    }
}
