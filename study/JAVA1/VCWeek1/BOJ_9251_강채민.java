import java.util.*;

public class 9251_ {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String s1 = input.next();
		String s2 = input.next();
		
		/**
		 * 참고한 링크입니다
		 * https://www.crocus.co.kr/787
		 * https://twinw.tistory.com/126
		 * 
		 * LCS라는 알고리즘을 어디서 들어봤는데.. 구현은 처음이였습니다
		 * 
		 * 참고한 링크를 이해하는것만도 1시간 넘게 걸렸던..
		 */
		
		/**
		 * 1. 일단 문자열에 다 0을 붙여준다.
		 * (관례라는데 이거 하는 이유를 잘 모르겠지만 그냥 dp채우는 거라고 생각함..)
		 */
		s1 = '0' + s1;
		s2 = '0' + s2;
		
		int dp[][] = new int[s1.length()][s2.length()];
		
		/**
		 * 2. 기준문자열을 s1으로 정하고 s2의 각각 알파벳과 비교한다.
		 */
		
		for(int i = 0; i < s1.length(); i++) {
			
			for(int j = 0; j < s2.length(); j++) {
				
				if(i == 0 || j == 0) {
					dp[i][j] = 0;
					continue; // 이거 안해줘서 indexoutofbounds났다..
				}
					
				
				/**
				 * 3-1. 같은 문자열이라면 왼쪽대각선 위 dp값 + 1을 한다.
				 */
				if(s1.charAt(i) == s2.charAt(j))
					dp[i][j] = dp[i-1][j-1] + 1;
				
				/**
				 * 3-2. 다른 문자열이라면 왼쪽dp값과 위쪽dp값중에 큰값이 온다
				 */
				else 
					dp[i][j] = Math.max(dp[i][j-1], dp[i-1][j]);
				
			}
		}
		
		System.out.println(dp[s1.length()-1][s2.length()-1]);// -> 잘나옴
		
		/*
		int find_i = s1.length() - 1;
		int find_j = s2.length() - 1;
		ArrayList<Integer>answer = new ArrayList<>();
		
		while(dp[find_i][find_j] != 0) {
			
			if(dp[find_i][find_j] == dp[find_i][find_j - 1])
				find_j--;
			
			else if(dp[find_i][find_j] == dp[find_i - 1][find_j])
				find_i--;
			
			else if((dp[find_i][find_j] - 1) == dp[find_i - 1][find_j - 1]) {
				
				find_i--;
				find_j--;
				answer.add(dp[find_i][find_j]);
			}
		}
		
		System.out.println(answer.size());
		*/
	}

}
