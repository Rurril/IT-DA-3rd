package itda_2020;

import java.util.*;

public class BOJ_9465_박소현  {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); 
		int T = scan.nextInt();
		for (int t=0;t<T;t++) {
			int N = scan.nextInt();
	
			int num[][] = new int[2][N+1];
			int DP[][] = new int[2][N+1];
			for (int i=1;i<=N;i++) {
				num[0][i] = scan.nextInt();
			}
			for (int i=1;i<=N;i++) {
				num[1][i] = scan.nextInt();
			}
			DP[0][0] = 0;
			DP[1][0] = 0;
			DP[0][1] = num[0][1];
			DP[1][1] = num[1][1];
			for (int i=2;i<=N;i++) {
				DP[0][i] = Math.max(DP[1][i-1], DP[1][i-2]) + num[0][i];
				DP[1][i] = Math.max(DP[0][i-1], DP[0][i-2]) + num[1][i];
			}
			
			/*for (int i=0;i<2;i++) {
				for (int j=0;j<=N;j++) {
					System.out.print(DP[i][j]+" ");
				}
				System.out.println();
			}
			*/
			System.out.println(Math.max(DP[0][N],DP[1][N]));
		}
	}

}
