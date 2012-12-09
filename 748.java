import java.math.BigDecimal;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		int n;
		BigDecimal R;
		String res;
		Scanner in = new Scanner(System.in);
		while (in.hasNext()) {
			R = in.nextBigDecimal();
			n = in.nextInt();
			R = R.pow(n).stripTrailingZeros();
			res = R.toPlainString();
			for (n = 0;; n++) {
				if (res.charAt(n) != '0')
					break;
			}
			System.out.println(res.substring(n));
		}
	}
}
