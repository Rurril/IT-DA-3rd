package itda_2020;

import java.util.Scanner;

public class BOJ_2504_박소현 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		String S = scan.next();
		char[] arr = S.toCharArray();
		for (int i=1;i<arr.length;i++) {
			if (arr[i-1]=='('&&arr[i]==')') {
				S =  S.substring(0,i-1)+"2"+S.substring(i+1,arr.length);
				arr = S.toCharArray();
			}
			if (arr[i-1]=='['&&arr[i]==']') {
				S =  S.substring(0,i-1)+"3"+S.substring(i+1,arr.length);
				arr = S.toCharArray();
			}
		}
		System.out.println(S);
		
		while (true) {
			for (int i =2;i<arr.length;i++) {
				int tmp = 0;
				if ('('==arr[i-2]&&')'==arr[i]) {
					tmp = Character.getNumericValue(arr[i-1])*2;
					S =  S.substring(0,i-2)+tmp+S.substring(i+1,arr.length);
					arr = S.toCharArray();
				}
				else if ('['==arr[i-2]&&']'==arr[i]) {
					tmp = Character.getNumericValue(arr[i-1])*3;
					S =  S.substring(0,i-2)+tmp+S.substring(i+1,arr.length);
					arr = S.toCharArray();
				}
				
			}
			if (arr.length==4) break;
			System.out.println(S);
		}
		
	}

}
