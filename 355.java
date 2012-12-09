import java.util.*;
import java.math.*;

public class Main {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		BigInteger dec;
		String str;
		int Frm, To;
		while (in.hasNext()) {
			Frm = in.nextInt();
			To = in.nextInt();
			str = in.nextLine().trim();
			if (isValid(str, Frm) == false) {
				System.out.println(str + " is an illegal base " + Frm
						+ " number");
				continue;
			}
			dec = convert_dec(str, Frm);
			String res = convert(dec, To);
			if (res == "")
				res = "0";
			System.out.println(str + " base " + Frm + " = " + res + " base "
					+ To);
		}
	}

	private static String convert(BigInteger dec, int To) {
		String ret = "";
		BigInteger _To = BigInteger.valueOf(To);
		while (dec != BigInteger.ZERO) {
			String t = dec.mod(_To).toString();
			int n = Integer.parseInt(t);
			if (n >= 10) {
				ret += ("ABCDEF").charAt(n - 10);
			} else {
				ret += t;
			}
			dec = dec.divide(_To);
		}
		return reverse(ret);
	}

	private static String reverse(String ret) {
		String str = "";
		int len = ret.length();
		for (int i = len - 1; i >= 0; i--) {
			str += ret.charAt(i);
		}
		return str;
	}

	private static BigInteger convert_dec(String str, int Frm) {
		BigInteger dec = BigInteger.ZERO;
		BigInteger temp, base = BigInteger.valueOf(Frm);
		int exp = 0;
		int len = str.length();
		for (int i = len - 1; i >= 0; i--) {
			temp = BigInteger.valueOf(change(str.charAt(i)));
			dec = dec.add(temp.multiply(base.pow(exp)));
			exp++;
		}
		return dec;
	}

	private static boolean isValid(String str, int frm) {
		int i, len = str.length(), chk;
		for (i = 0; i < len; i++) {
			chk = change(str.charAt(i));
			if (chk >= frm)
				return false;
		}
		return true;
	}

	private static int change(char charAt) {
		int chk = charAt - 48;
		if (charAt >= 'A' && charAt <= 'Z')
			chk = charAt - 'A' + 10;
		return chk;
	}
}
