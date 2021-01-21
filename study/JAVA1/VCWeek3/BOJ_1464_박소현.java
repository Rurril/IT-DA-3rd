package itda_2020;

import java.util.Scanner;

public class BOJ_1464_박소현 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String S = scan.next();
		int count = S.length();
		char[] arr = S.toCharArray();
		//char[] result = new char[S.length()];
		for (int i=1;i<count;i++ ) {
			if (arr[i]> arr[i-1]) {
				S = arr[i] + S.substring(0,i)+S.substring(i+1,count);
				

				
				//System.out.println(S);
			}
		}
		for (int i = S.length() -1; i>=0; i--) {
	         System.out.print(S.charAt(i));
	      }
	}

}
