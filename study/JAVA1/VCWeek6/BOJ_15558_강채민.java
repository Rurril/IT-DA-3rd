import java.util.*;

public class 15558_점프게임 {

	public static void main(String[] args) {
		
		/**
		 * 처음에 메모리 초과가 나서 구글링 했습니다...
		 * 
		 *  https://github.com/Rurril/IT-DA-3rd/blob/07e5463d5fa309a8face0f502fa4dacd5ba333f5/study/C%2B%2B1/VCWeek6/BOJ_15558_%EC%96%91%EC%9C%A4%ED%9D%AC.cpp
		 *  처음에는 팀원 코드를 참고했고
		 *  
		 *  그밖에 메모리초과나 틀렸습니다는 질문과 구글링으로 찾았습니다.
		 *  https://lmcoa15.tistory.com/104 (메모리 초과 참고)
		 */
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int K = input.nextInt();
		
		ArrayList<Integer> Jump [] = new ArrayList[2];
		
		for(int a = 0; a < 2; a++) {
			
			Jump[a] = new ArrayList();
			
			String S = input.next();
			
			for(int s = 0; s < S.length(); s++) 
				Jump[a].add(S.charAt(s) - '0');
			
		}
			
		Queue<Integer> QIndex = new LinkedList<>();
		Queue<Integer> QLR = new LinkedList<>();
		
		QIndex.add(0);
		QLR.add(0); // 왼쪽부터 시작
		
		/**
		 * 앞으로 뒤로 가는거랑 반대편 줄로 옮기는 작업까지 배열로 넣어버림
		 */
		int move[][] = {{1, 0}, {-1, 0}, {K, -1}, {K, 1}}; 
		
		Queue<Integer> Qtime = new LinkedList<>();
		Qtime.add(0);
		
		/**
		 * 방문을 체크해줘야하는구나.....
		 */
		
		int check[][] = new int[2][N];
		check[0][0] = 1; // 왼쪽 0번부터 시작
		
		while(!QIndex.isEmpty()) {
			
			int index = QIndex.poll(); // 갈 번호
			int location = QLR.poll(); // 왼쪽인지 오른쪽인지
			
			int time = Qtime.poll();
			
			for(int m = 0; m < move.length; m++) {
				
				int go_index = index + move[m][0];
				int go_location = location + move[m][1];
				
				if(go_index >= N) {
					System.out.println(1);
					return;
				}
				
				//if(go_location < 0 || go_location > 1 || go_index < time || Jump[go_location].get(go_index) == 0)
				if(go_location < 0 || go_location > 1 || go_index <= time || Jump[go_location].get(go_index) == 0)
					continue;
				
				/**
				 * 이미 갔던 곳이닞도 체크해줘야 한다.
				 */
				
				if(check[go_location][go_index] == 1)
					continue;
				
				QIndex.add(go_index);
				QLR.add(go_location);
				
				Qtime.add(time+1);
				
				check[go_location][go_index] = 1;
			}
			
			//time++;
			
		}
		
		System.out.println(0);

	}

}
