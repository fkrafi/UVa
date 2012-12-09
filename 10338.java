import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        BigInteger fact[] = new BigInteger[25];
        BigInteger d, ans;
        int n, t, len, i, j, con, cnt, k=1;
        fact[0] = BigInteger.valueOf(1);
        fact[1] = BigInteger.valueOf(1);
        for(i=2; i<=20; i++)
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        String str;
        t = in.nextInt();
        in.nextLine();
        while(t>0)
        {
            t--;
            str = in.nextLine();
            len = str.length();
            d = BigInteger.ONE;
            for(i=0; i<len; i++)
            {
                con = 1;
                for(j=0; j<i; j++)
                {
                    if(str.charAt(i) == str.charAt(j))
                    {
                        con = 0;
                        break;
                    }
                }
                if(con==1)
                {
                    cnt = 1;
                    for(j=i+1; j<len; j++)
                    {
                        if(str.charAt(j) == str.charAt(i))
                            cnt++;
                    }
                    d = d.multiply(fact[cnt]);
                }
            }
            ans = fact[len].divide(d);
            System.out.println("Data set " + k + ": " + ans);
            k++;
        }
    }
}