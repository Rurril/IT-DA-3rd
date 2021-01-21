import java.util.*;

public class 5904_Moo개빡쳐 {

	static String answer = "";
	
	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		/**
		 * https://kwoncorin.tistory.com/54
		 * 
		 * 문제 이해를 이제야 했다.. 
		 * 
		 * 처음에는 N이 11일때 S(N)을 찾으라는줄 알았다가 N번째라고 해서
		 * 다시 S(N)을 구해서 N번째를 구한..
		 * 
		 * 요지는 S(K)문자열에서 N번째 문자를 구하는거였다..
		 */
     
		/**
		 * 1. 일단 N번째보다 긴 S(K)를 찾는다.
		 * 2. 그래서 그 N번째가 S(K-1) 구간인지, moo..구간인지 찾아준다.
		 * S(K-1)구간이라면 다시 재귀로 거기를 찾는다.
		 */
		
		Moo(N);
		System.out.println(answer);
	}
	
	public static void Moo(int N) {
		
		int len_N = 3; // S(0) = "moo" -> 3
		int K = 0; // 처음 S(0)에서 K는 0이다.
		int front_len = 0; // N보다 긴 S를 찾을때 그 전의 길이를 담을 변수
		
		if(N == 1)
			answer = "m";
		
		else if(N <= 3)
			answer = "o";
		
		else {
			while(len_N < N) {
	
				front_len = len_N;
				len_N = len_N * 2; // S(K-1)이 2번 반복되니까
				len_N = len_N + K + 4; // S(1)에서 "mooo".
				K++; // K+2개로 계속 늘어나고 S(2)에서는 "moooo"으로 5개.
				//front_len = len_N;
			}
			
			if(len_N - front_len + 1 <= N)
				Moo(N - len_N + front_len);
			
			else if(front_len + 1 == N) // S(K-1) 다음에 "mo.."에서 m일때
				answer = "m";
			
			else
				answer = "o";
		}
	}

}
