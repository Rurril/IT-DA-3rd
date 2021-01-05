import java.util.*;

public class 1915_민입니다 {

	public static void main(String[] args) {
		
		/**
		 * https://suriisurii.tistory.com/13 참고했습니다
		 * 정사각형의 길이로 구할려는 나는...한심했음
		 */
		
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt(); // 가로
		int M = input.nextInt(); // 세로
		
		int map[][] = new int[N][M];
		int dp[][] = new int[N][M];
		int max = 0;
		
		for(int i = 0; i < N; i++) {
			
			String s = input.next();
			
			for(int j = 0; j < M; j++)  {
				map[i][j] = s.charAt(j) - '0';
				
				if(map[i][j] == 1) {
					max = 1;
					dp[i][j] = 1;
				}
					
			}
				
			
		}
		
		/*
		for(int i = 0; i < N; i++) {
			
			for(int j = 0; j < M; j++)
				System.out.print(map[i][j] + " ");
			
			System.out.println();
		}
		
		*/
		
		//int dp[][] = map.clone(); -> 위에서 max를 1로 설정해주는거때문에 의미가 없어짐
		
		//int max = 0; -> 위로 옮김
		
		
		for(int i = 1; i < N; i++) {
			
			for(int j = 1; j < M; j++) {
				
				/**
				 * 왼쪽 대각선 위 i-1 j-1
				 * 위에 i-1 j
				 * 왼쪽 i j-1
				 */
				if(map[i-1][j-1] == 1 && map[i-1][j] == 1 && map[i][j-1] == 1) {
					
					dp[i][j] = Math.min(dp[i-1][j-1], dp[i-1][j]);
					dp[i][j] = Math.min(dp[i][j], dp[i][j-1]) + 1;
					
					max = Math.max(dp[i][j], max);
				}
			}
		}
		
		System.out.println(max * max);

	}

}
