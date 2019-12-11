import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class C
{
	public static BigInteger[] ans = new BigInteger[20];
	public static int n, m;
	public static final BigInteger TWO = new BigInteger ("2");
	public static PrintWriter writer;
	
	public static BigInteger isnPrime (BigInteger val) {
		for (BigInteger i=TWO; i.multiply(i).compareTo(val) <= 0; i = i.add(BigInteger.ONE)) {
	        if (val.mod(i).equals(BigInteger.ZERO)) return i;
	        if (n>12 && i.compareTo(BigInteger.TEN.pow(4))>0) return BigInteger.ZERO;
	    } return BigInteger.ZERO;
	}
	
	public static boolean isValid (BigInteger val) {
		//System.out.println(val + " = val20");
		int it = 0;
		BigInteger base, res;
		BigInteger total, mm, pp;
		
		for (base=TWO; base.compareTo(BigInteger.TEN) <= 0; base = base.add(BigInteger.ONE)) {
			total = new BigInteger ("0");
			mm = new BigInteger ("1");
			pp = new BigInteger ("1");
			for (int i=0; i<n; i++) {
				if (val.and(pp).compareTo(BigInteger.ZERO) != 0) {
					total = total.add(mm);
				}
				pp = pp.multiply(TWO);
				mm = mm.multiply(base);
			}
			//System.out.println(total + " = total, base = " + base);
			res = isnPrime(total);
			if (res.compareTo(BigInteger.ZERO)==0) return false;
			//System.out.println(res + " " + total + " " + pp + " " + mm);
			ans[it] = res;
			it++;
		}
		
		return true;
	}
	
	public static void rec(BigInteger val, int lev, BigInteger pp) {
		if (lev == 0) return;
		rec(val,lev-1,pp.multiply(TWO));
		if (val.and(pp).compareTo(BigInteger.ZERO) == 0) { writer.print("0"); }
		else { writer.print("1"); }
		return;
	}
	
	public static void prts(BigInteger val) {
		rec(val,n,BigInteger.ONE);
	}
	
	public static void main (String[] args) throws java.lang.Exception
	{
		File input = new File("/home/labib/Desktop/Practice/Online Contest/Codejam/C-large.in");
		writer = new PrintWriter("/home/labib/Desktop/Practice/Online Contest/Codejam/output.txt", "UTF-8");
		
		try {
			Scanner in = new Scanner(input);
			
			int t, tc = 0;
			BigInteger i;
			
			t = in.nextInt();
			while (tc<t) {
				tc++;
				writer.println("Case #" + tc + ":");
				
				n = in.nextInt();
				m = in.nextInt();
				
				i = new BigInteger("2");
				i = i.pow(n-1);
				i = i.add(BigInteger.ONE);
				
				
				while (m>0) {
					//System.out.println(i + " = i");
					if (isValid(i)) {
						m--;
						//System.out.print(i + " ");
						prts(i);
						for (int j=0; j<9; j++) {
							writer.print(" " + ans[j]);
						}
						writer.println("");
					}
					i = i.add(TWO);
				}
			}
			in.close();
		}
		catch (FileNotFoundException e) {
	        e.printStackTrace();
	    }
		writer.close();
	}
}
