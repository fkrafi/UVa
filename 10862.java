import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger fib[] = new BigInteger[4010];
        fib[0] = BigInteger.ZERO;
        fib[1] = BigInteger.ONE;
        int i;
        for(i=2; i<=4000; i++)
            fib[i] = fib[i-1].add(fib[i-2]);
        while(true)
        {
            i = in.nextInt();
            if(i==0)break;
            System.out.println(fib[2*i]);
        }
    }
}