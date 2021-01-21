package 백준공부;

import java.util.*;

public class BOJ2502 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int D = scan.nextInt();
		int K = scan.nextInt();
		int DP[][] = new int[31][2];
		
		DP[0][0] = 0;
		DP[0][1] = 0;
		DP[1][0] = 1;
		DP[1][1] = 0;
		DP[2][0] = 0;
		DP[2][1] = 1;
		
		for (int i=3;i<31;i++) {
			DP[i][0] = DP[i-2][0]+DP[i-1][0];
			DP[i][1] = DP[i-2][1]+DP[i-1][1];
		}
		

		/*for (int i=1;i<31;i++) {
				System.out.printf("%d 번째a %d\n",i, DP[i][0]);
				System.out.printf("%d 번째b %d\n",i, DP[i][1]);
		}
		*/
		//if (D==3) {
			
		//	return ;
		//}
		for (int i=1;i<=K;i++) {
			for (int j=1;j<=K;j++) {
				if (DP[D][0]*i+DP[D][1]*j==K) {
					System.out.printf("%d\n%d",i,j);
					return;
				}
 			}
		}	
		
		
	}
}
