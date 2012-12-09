import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n;
		BigInteger res;
		while (true) {
			n = in.nextInt();
			if (n == 0)
				break;
			res = BigInteger.valueOf(2 * n + 1);
			res = res.multiply(BigInteger.valueOf(n + 1));
			res = res.multiply(BigInteger.valueOf(n));
			res = res.divide(BigInteger.valueOf(6));
			System.out.println(res);
		}
	}
}
