import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        BigInteger f[] = new BigInteger[1000];
        int i;
        f[1] = BigInteger.ONE;
        f[2] = new BigInteger("2");
        BigInteger comp = BigInteger.valueOf(10).pow(100);
        for(i=3; ; i++)
        {
            f[i] = f[i-1].add(f[i-2]);
            if(f[i].compareTo(comp) > 0)break;
        }
        BigInteger a, b;
        int cnt;
        while(true)
        {
            a = in.nextBigInteger();
            b = in.nextBigInteger();
            if(a.compareTo(BigInteger.ZERO)==0 && b.compareTo(BigInteger.ZERO)==0)break;
            cnt = 0;
            for(i=1; ; i++)
            {
                if(f[i].compareTo(b)>0)break;
                if( f[i].compareTo(a)>-1 )
                    cnt++;
            }
            System.out.println(cnt);
        }
    }
}