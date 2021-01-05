import java.util.*;

public class 4172_민입니다 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		/**
		 * 처음에 문제보고 매우 당황
		 * ln함수는 처음 봤던거같다. 내장함수가 있는지도..
		 */
		
		int dp[] = new int[1000001];
		
		dp[0] = 1;
		
		for(int i = 1; i < 1000000; i++) {
			
			int sqrt_i = (int) (i - Math.sqrt(i));
			int log_i = (int) Math.log(i);
			int sin_i = (int) (i * Math.sin(i) * Math.sin(i));
			
			dp[i] = (dp[sqrt_i] + dp[log_i] + dp[sin_i]) % 1000000;
		}
		
		while(true) {
			
			int N = input.nextInt();
			
			if(N == -1)
				break;
			
			System.out.println(dp[N]);
		}
	}

}
