import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n, m, i, k, c=1;
        BigInteger v, p, s, M;
        Scanner in = new Scanner(System.in);
        while(true)
        {
            n = in.nextInt();
            m = in.nextInt();
            if(n==0 && m==0)break;
            s = new BigInteger("0");
            M = new BigInteger(Integer.toString(m));
            for(i=0; i<n; i++)
            {
                v = in.nextBigInteger();
                s = s.add(v);
            }
            p = s.divide(M);
            System.out.println("Bill #" + c + " costs " + s +": each friend should pay " + p);
            System.out.println();
            c++;
        }
    }
}
