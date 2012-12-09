import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		int cs = 1, a, b;
		BigInteger res;
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			a = in.nextInt();
			b = in.nextInt();
			if (a == 0 && b == 0)
				break;
			BigInteger ta = BigInteger.valueOf(a);
			BigInteger tb = BigInteger.valueOf(b);
			res = ta.multiply(tb);
			res = res.multiply(BigInteger.valueOf(a - 1));
			res = res.multiply(BigInteger.valueOf(b - 1));
			res = res.divide(BigInteger.valueOf(4));
			System.out.println("Case " + cs++ + ": " + res);
		}
	}

}
