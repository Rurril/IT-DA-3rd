import java.util.*;

public class 뿌요채민 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		String map [][] = new String[12][6];
		
		/**
		 * https://jaimemin.tistory.com/722
		 * 참고했습니다.
		 * 
		 * 음.. 처음 문자열이 나온것을 찾기는 어렵겠다..
		 * 
		 * 정렬을 위해서 우선순위 큐를 쓸 수도 있다. 
		 * 하지만 우선순위 큐는 복잡해서 안쓸려고한다.. Deque로 자유자재로 할래..
		 * 
		 * 접근 1. 문자열 전체 개수를 세서 모든 문자열을 다 탐색했으면 종료할려고 생각
		 * -> .과 문자를 따로 구분하기 힘들어서 그냥 무한루프를 썼다..
		 */

		for(int m1 = 0; m1 < 12; m1++) {
			
			String S = input.next();
			
			map[m1] = S.split("");
		}
		
		//1. 탐색 Q
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		//2. 같은 문자열 담을 Q
		/*
		Queue<Integer> findX = new LinkedList<>();
		Queue<Integer> findY = new LinkedList<>();
		*/
		Deque<Integer> findX = new LinkedList<>();
		Deque<Integer> findY = new LinkedList<>();
		
		//int check[][] = new int[12][6];
		int move_x[] = {0, 0, 1, -1};
		int move_y[] = {1, -1, 0, 0};
		
		int answer = 0;
		
		while(true) {
			
			int check[][] = new int[12][6]; // 한판을 돌때마다 갱신해야한다.
			
			for(int i = 0; i < 12; i++) {
				
				for(int j = 0; j < 6; j++) {
					
					//if(map[i][j].equals(".")) // 바본가..
					if(map[i][j].equals(".") || check[i][j] == 1)
						continue;
					
					int count = 0;
					
					QX.add(i);
					QY.add(j);
					check[i][j] = 1;
					count++;
					
					/**
					 * Deque 쓰는게 익숙하지 않아서 고생했다..
					 */
					findX.add(i);
					findY.add(j);
					/*
					findX.addFirst(i);
					findY.addFirst(j);
					*/
					
					while(!QX.isEmpty()) {
						
						int X = QX.poll();
						int Y = QY.poll();
						
						for(int mx = 0; mx < move_x.length; mx++) {
							
							int go_x = X + move_x[mx];
							int go_y = Y + move_y[mx];
							
							if(go_x < 0 || go_y < 0 || go_x >= 12 || go_y >= 6)
								continue;
							
							if(check[go_x][go_y] == 1 || map[go_x][go_y].equals("."))
								continue;
							
							if(!map[X][Y].equals(map[go_x][go_y]))
								continue;
							
							QX.add(go_x);
							QY.add(go_y);
							check[go_x][go_y] = 1;
							count++;
							
							findX.add(go_x);
							findY.add(go_y);
						}
					}
					
					if(count >= 4)
						continue;
            
					else {
						//count수 만큼 문자열 담은 Queue에서 뽑아줘야한다.
						for(int c = 0; c < count; c++) {
							findX.removeLast();
							findY.removeLast();
						}
					}
				}
			}
			/**
			 * 한판을 다 돌고 나왔으면 이제 부셔야지...
			 */
			int flag = 0;
			
			while(!findX.isEmpty()) {
				flag = 1;
				
				int fx = findX.poll();
				int fy = findY.poll();
				
				map[fx][fy] = ".";
				
				for(int i = fx-1; i >= 0; i--) {
					
					if(map[i][fy].equals("."))
						break;
					
					map[i+1][fy] = map[i][fy];
					map[i][fy] = ".";
				}
			}
			
			/**
			 * 부실게 없으면 while무한루프 빠져나가기
			 */
			if(flag == 0) 
				break; 
			else {
				answer++;
			}
		}
		
		//하나도 터지지 않는다면 0을 출력한다. -> 이미 answer를 0으로 줬다.
		System.out.println(answer);
	}

}
