import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int _N, D;
		BigInteger N;
		while (true) {
			_N = in.nextInt();
			D = in.nextInt();
			if (_N == 0 && D == 0)
				break;
			N = BigInteger.valueOf(_N);
			System.out.println(N.pow(D));
		}
	}
}
