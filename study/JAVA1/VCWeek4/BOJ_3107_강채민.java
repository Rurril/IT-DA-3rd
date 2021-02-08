import java.util.*;

public class 3107_늦었습니다 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String S = input.next();
		
		String ipv6 [] = S.split(":");
		
		String zero = "0000";
		String answer = "";
		int flag = 0;
		
		/**
		 * 1:2:: 이런 경우가 먹히지 않았다..
		 * 그리고 ::으로 묶는 경우가 0집합이 1개인 경우도 있기 때문에
		 * ::1:2:3:4:5:6:7 이러한 경우도 잘 출력해야 했다.
		 */
		
		/**
		 * 1. 아얘 예외처리를 하기 귀찮아서 그냥 일단 0000을 8개 집단으로 만들었다.
		 */
		ArrayList<String> result = new ArrayList<>();
		for(int r = 0; r < 8; r++)
			result.add("0000");

		/**
		 * index라는 변수를 추가해서 ipv6배열에서 i번째인걸 result의 index번째에 넣도록 하였다.
		 */
		int index = 0;
		
		for(int i = 0; i < ipv6.length; i++) {
			
			if(ipv6[i].length() == 4) {
				//answer = answer + ipv6[i];
				//result.set(i, ipv6[i]);
				result.set(index, ipv6[i]); // result배열이 0000이니까 그걸 바꿔준다.
				index++;
			}
			
			else if(ipv6[i].length() > 0) {
				ipv6[i] = (zero.substring(0, 4 - ipv6[i].length())) + ipv6[i];
				//answer = answer + ipv6[i];
				//result.set(i, ipv6[i]);
				result.set(index, ipv6[i]);
				index++;
			}
			
			else { //(ipv6[i].length() == 0)
				
				if(flag == 0) {
					
					flag = 1;
					
					int N = 8 - (ipv6.length) + 1;
					
					//result배열에 추가..
					//int index = i;
					
					for(int j = 0; j < N; j++) {
						//answer = answer + "0000" + ":";
						//result.re
						//result.set(index, element)
						/**
						 * 이미 result 배열에 0000이 있으니까 index만 늘려주면 된다.
						 */
						index++;
					}
				}
				
				else {
					//answer = answer + "0000";
					//result.set(index, "")
					
					/**
					 * 역시 마찬가지로 index만 늘려주면 된다.
					 */
					index++;
				}
					
				
			}
			//answer = answer + ":";
		}
		
		//System.out.println(answer.substring(0, answer.length() - 1));
		
		/**
		 * result배열에 있는걸 꺼내서 :을 붙여주도록 하였다.
		 */
		for(int a = 0; a < result.size(); a++) {
			answer = answer + result.get(a) + ":";
		}
    
		System.out.println(answer.substring(0, answer.length() - 1));
		
	}

}
