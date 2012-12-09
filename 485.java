import java.util.*;
import java.math.*;

public class Pascal {
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        BigInteger a[] = new BigInteger[100000], last, temp;
        BigInteger m = new BigInteger("1000000000000000000000000000000000000000000000000000000000000");
        int con=0, sz=3, i;
        System.out.println("1");
        System.out.println("1 1");
        System.out.println("1 2 1");
        a[0] = BigInteger.ONE; a[1] = new BigInteger("2"); a[2] = BigInteger.ONE;
        while(true){
            System.out.print("1");
            last = a[0];
            for(i=1; i<sz; i++){
                temp = a[i];
                a[i] = a[i].add(last);
                last = temp;
                System.out.print(" " + a[i]);
                if( a[i].compareTo(m)>0 )con = 1;
            }
            a[i] = BigInteger.ONE;
            System.out.println(" 1");
            sz++;
            if(con==1)break;
        }
    }
}
