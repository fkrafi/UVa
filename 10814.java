import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger p, q, r;
        int t;
        t = in.nextInt();
        while(t>0)
        {
            t--;
            p = in.nextBigInteger();
            in.next();
            q = in.nextBigInteger();
            r = p.gcd(q);
            p = p.divide(r);
            q = q.divide(r);
            System.out.println(p + " / " + q);
        }
    }
}