import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		int t;
		BigDecimal sum, n;
		Scanner in = new Scanner(System.in);
		t = in.nextInt();
		while (t > 0) {
			t--;
			sum = BigDecimal.ZERO;
			n = in.nextBigDecimal();
			while (n.equals(BigDecimal.ZERO) == false) {
				sum = sum.add(n);
				n = in.nextBigDecimal();
			}
			int i;
			String str = sum.toString();
			// System.out.println(str);
			for (i = str.length() - 1; i >= 0; i--) {
				if (str.charAt(i) == '.' || str.charAt(i) != '0') {
					break;
				}
			}
			if (i < str.length() - 1 && i > 0 && str.charAt(i) == '.') {
				i--;
			}
			str = str.substring(0, i + 1);
			System.out.println(str);
		}
	}
}
