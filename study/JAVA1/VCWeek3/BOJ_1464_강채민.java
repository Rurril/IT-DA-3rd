import java.util.*;

public class 1464_나혼자dfs로 풀고^^ {
	
	//static String S;
	//static ArrayList<String> answer = new ArrayList<>();

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		/**
		 * 1. for문을 이용해서 문자열 다 뒤집어서 전체문자열을 나열한 뒤 Sort했습니다.
		 */
		/**
		 * 2. 위에꺼가 메모리 초과가..
		 * BFS방식이나 DFS 방식으로 다 넣어서 비교해야하나..?
		 */
		
		/*
		S = input.next();

		dfs(S, 1);
		
		Collections.sort(answer);
		
		System.out.println(answer.get(0));
		*/
		
		/**
		 * bfs나 dfs으로 어떻게 접근해야할지 몰라서 
		 * 잇다 사람들은 어떻게 풀었는지 참고하려고 커밋기록을 봤습니다..
		 * 
		 * 파이썬팀 코드 참고했습니다
		 * 그리고 너무나 충격적인..ㅜ
		 * 그냥 문자열 하나씩 돌면서 순서대로 하면 되는거였어..?
		 * 이게 왜 Gold이죠...? 눈물나네
		 */
		
		//if("A" < "B") -> 파이썬은 되는데 자바 안됨. 화남
		
		/*두 문자열이 사전 순으로 같다면 0을 반환
			사전 순으로 앞선 경우 음수를 반환.
			사전순으로 뒤질 경우 양수를 반환. 
		 */
		
		String S = input.next();
		String answer = Character.toString(S.charAt(0));
		
		for(int i = 1; i < S.length(); i++) {
			
			String s1 = Character.toString(S.charAt(i));
			String s2 = Character.toString(answer.charAt(0));
			
			if(s1.compareTo(s2) <= 0) 
				answer = S.charAt(i) + answer;
			else
				answer = answer + S.charAt(i);
		}
		
		System.out.println(answer);
		
	}
	
	/*
	public static void dfs(String st, int i) {
		
		if(i == S.length()) {
			answer.add(st);
			return;
		}
		
		dfs(st, i+1);
		
		StringBuilder sb = new StringBuilder();
		
		//1. i개 문자를 뒤집었을때
		sb.append(st.substring(0, i+1));
		String s1 = sb.reverse() + st.substring(i+1);
		
		dfs(s1, i+1);
	}
	*/
}
