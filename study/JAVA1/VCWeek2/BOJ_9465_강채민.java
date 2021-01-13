import java.util.Scanner;

public class 9465_채민 {

	public static void main(String[] args) {

		/**
		 * https://m.blog.naver.com/occidere/220786307316
		 * 참고했습니다.
		 */
		Scanner input = new Scanner(System.in);
		
		int T = input.nextInt();
		
		for(int t = 0; t < T; t++) {
			
			int N = input.nextInt();
			
			int map[][] = new int[2][N+1];
			int dp[][] = new int[2][N+1];
			
			for(int i = 0; i < 2; i++) {
				for(int j = 1; j <= N; j++)
					map[i][j] = input.nextInt();
			}
			
			dp[0][1] = map[0][1];
			dp[1][1] = map[1][1];
			
			for(int i = 2; i <= N; i++) {
				
				dp[0][i] = Math.max(dp[1][i-2], dp[1][i-1]) + map[0][i];
				dp[1][i] = Math.max(dp[0][i-2], dp[0][i-1]) + map[1][i];
			}
			
			System.out.println(Math.max(dp[0][N], dp[1][N]));
		}
	}

}
