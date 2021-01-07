package 백준공부;

import java.util.Scanner;

public class BOJ4172 {
	static int DP[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int[] DP = new int[1000001];
		DP[0] = 1;
			for (int i= 1; i<1000000;i++) {
				//System.out.println("i	" + i);
				//int sqrt = DP[(int) Math.floor(i-Math.sqrt(i))];
				int sqrt = (int)(i-Math.sqrt(i));
				//System.out.println("sqrt	" + sqrt);
				int ln = (int)(Math.log(i));
				//int ln = DP[(int) Math.floor(Math.log(i))];
				//System.out.println("ln	" + ln);
				int sin = (int)(i*Math.sin(i)*Math.sin(i));
				//int sin = DP[(int) Math.floor(i*Math.sin(i)*Math.sin(i))];
				//System.out.println("sin		" + sin);
				
				
				DP[i] = (DP[sqrt]+DP[ln]+DP[sin])%1000000;
				//System.out.printf("인덱스 %d는	%d\n",i,DP[i]);
			}
			while(true) {
				int N = scan.nextInt();
				if(N==-1) break;
				System.out.println(DP[N]);
				//System.out.printf("%d\n",DP[N]%1000000);
		
			}
	}
}