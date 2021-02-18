import java.util.*;

public class 8911_ㅊㅁ {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		
		/*
		int move_x[] = {1, -1, 0, 0}; // 동서남북
		int move_y[] = {0, 0, -1, 1};
		*/
		
		/**
		 * 동서남북하니까 회전시키기가 힘드네 ㅎ..
		 * 방법은 잇다 사람들 코드를 참고했습니다..
		 */
		int move_x[] = {0, 1, 0, -1}; // 북동남서
		int move_y[] = {1, 0, -1, 0};
		
		for(int i = 0; i < N; i++) {
			
			//int dir = 3; // 기본은 북쪽을 보도록
			int dir = 0; // 기본은 북쪽을 보도록
			int x = 0;
			int y = 0;
			
			int max_x = 0;
			int min_x = 0;
			int max_y = 0;
			int min_y = 0;
			
			String S = input.next();
			
			for(int n = 0; n < S.length(); n++) {
				
				if(S.charAt(n) == 'F') {
					x = x + move_x[dir];
					y = y + move_y[dir];
				}
				
				else if(S.charAt(n) == 'B') {
					x = x - (move_x[dir]);
					y = y - (move_y[dir]);
				}
				
				else if(S.charAt(n) == 'L') {
					if(dir == 0)
						dir = 3; // 북쪽을 바라보고있으면 L은 서쪽이 된다.
					else
						dir = dir - 1;
				}
					
				
				else { //(S.charAt(n) == 'R')
					if(dir == 3) // 서쪽을 바라보고 있으면 R은 북쪽이 된다.
						dir = 0;
					else
						dir = dir + 1;
				}
					
				
				max_x = Math.max(x, max_x);
				min_x = Math.min(x, min_x);
				
				max_y = Math.max(y, max_y);
				min_y = Math.min(y, min_y);
			}
			
			System.out.println((max_x - min_x) * (max_y - min_y));
		}
	}

}
