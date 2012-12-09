import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger fib[] = new BigInteger[1010];
        int i;
        fib[0] = BigInteger.valueOf(1);
        fib[1] = BigInteger.valueOf(2);
        for(i=2; i<=1000; i++)
            fib[i] = fib[i-1].add(fib[i-2]);
        while(in.hasNext())
        {
            i = in.nextInt();
            System.out.println(fib[i]);
        }
    }
}