import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Reverse3 {

	public static void main(String[] args) throws IOException {
		// 그리디 알고리즘
		// 모든 경우의 수를 구해서 비교하기엔 테스트케이스가 너무 많음..
		// 규칙 : 비교대상이 되는 맨앞 글자와(왜냐하면 이게 리버스 시켰을때 위치가 바뀌는 놈이니까)사전순으로 정렬되있을때는 가만히 두다가, 사전순 앞으로 오는게 나오면 리버스 한 번 두 번 해주는 식.
		// 개빡치게 100퍼센트 틀렸습니다 뜸 ㅡㅡ ->는 길이 1일때 고려안해서..ㅋㅋㅋㅋㅋㅋ
		String s;
		String sol = "";
		StringBuilder sb;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		s = br.readLine();
		
		if(s.length() == 1) {
			sol = s;//이거 안처리해줘서 틀렸음.. 근데 좀 하드코딩인듯
		}
		
		for(int i = 1; i < s.length(); i++) {
			if(s.charAt(i) <= s.charAt(0)) {
				sb = new StringBuilder(s.substring(0, i));
				sb.reverse();
				sb.append(s.charAt(i));
				sol = sb.reverse().toString();
				if(i != s.length() - 1) {
					s = sb.toString() + s.substring(i + 1, s.length());
				}
			}
			else {
				sol = s.substring(0, i+1);
			}
		}
		
		System.out.println(sol);
	}

}
