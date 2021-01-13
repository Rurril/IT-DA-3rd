package 백준공부;

import java.util.Scanner;

public class BOJ1915 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		scan.nextLine();
		int w = 0,ret=0;
		int num[][] = new int[1001][1001];
		int DP[][] = new int[1001][1001];
		for (int i=1;i<=N;i++) {
			char[] str =scan.nextLine().toCharArray();
			//System.out.print(str);
			for (int j=1;j<=M;j++) {
				num[i][j] = Character.getNumericValue(str[j-1]);
				//System.out.print(num[i][j]+" ");
				if(num[i][j]==1) DP[i][j]=1;
			}
			//System.out.println();
		}
		
		/*for (int i=1;i<=N;i++) {
			for (int j=1;j<=M;j++) {
				System.out.print(num[i][j]+" ");
			}
			System.out.println();
		}
		*/
		for (int i=1;i<=N;i++) {
			for (int j=1;j<=M;j++) {
				 if (num[i][j] == 1) {
					 if (DP[i-1][j] != 0 && DP[i-1][j-1] != 0 && DP[i][j-1] != 0) {
						 if (DP[i-1][j] != 1 && DP[i-1][j-1] != 1 && DP[i][j-1] != 1) {
							 int size = Math.min(DP[i-1][j], DP[i-1][j-1]);
		                     size = Math.min(size, DP[i][j-1]);
		                     w = (int) (Math.sqrt(size) + 1);
		                     DP[i][j] = w * w;
						 }
						 else {
							 DP[i][j] = 4;
						 }
					 }
					 ret = Math.max(ret, DP[i][j]);
				 }
			}
		}
		System.out.println(ret);
	}

}
