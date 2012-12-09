import java.math.BigInteger;
import java.util.Scanner;

public class Multifactorials {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		String str;
		int n, k, T, cs, len, i, temp, s, a;
		int div[] = new int[1005];
		BigInteger res;
		T = in.nextInt();
		for (cs = 1; cs <= T; cs++) {
			str = in.next();

			len = str.length();
			n = k = 0;
			for (i = 0; i < len; i++) {
				if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
					n = n * 10 + str.charAt(i) - 48;
				} else if (str.charAt(i) == '!') {
					k++;
				}
			}
			a = n;

			len = (n % k == 0) ? k : (n % k);
			for (i = 0; i <= n; i++) {
				div[i] = 0;
			}

			do {
				temp = n;
				s = (int) Math.sqrt(temp);
				while (temp % 2 == 0) {
					div[2]++;
					temp /= 2;
				}
				for (i = 3; i <= s; i += 2) {
					while (temp % i == 0) {
						div[i]++;
						temp /= i;
					}
				}
				if (temp != 1) {
					div[temp]++;
				}
				n -= k;
			} while (n >= len);

			res = BigInteger.ONE;
			boolean flag = true;

			for (i = 2; i <= a; i++) {
				if (div[i] != 0) {
					res = res.multiply(BigInteger.valueOf(div[i] + 1));
				}

				if (res.compareTo(new BigInteger("1000000000000000000")) == 1) {
					flag = false;
					break;
				}
			}

			if (flag == false) {
				System.out.println("Case " + cs + ": Infinity");
			} else {
				System.out.println("Case " + cs + ": " + res);
			}

		}
	}
}
