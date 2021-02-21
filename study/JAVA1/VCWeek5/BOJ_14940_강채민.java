import java.util.*;
import java.io.*;

public class 14940_ {

	public static void main(String[] args) throws IOException {
		
		/**
		 * Scanner로 하면 시간초과가 나네.......
		 * BufferedReader를 써야하네요...
		 * 
		 * 아 그리고 우리 팀장님 코드 참고했습니다!
		 * 팀장님 최고!!!^^
		 * 
		 * https://github.com/Rurril/IT-DA-3rd/blob/master/study/JAVA1/VCWeek5/BOJ_14940_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 */
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		int map[][] = new int[N][M];
		int result[][] = new int[N][M];
		int check[][] = new int[N][M];
		
		int move_x[] = {1, -1, 0, 0};
		int move_y [] = {0, 0, 1, -1};
		
		int start_x = 0;
		int start_y = 0;
		
		for(int n = 0; n < N; n++) {
			
			st = new StringTokenizer(br.readLine());
			
			for(int m = 0; m < M; m++) {
				map[n][m] = Integer.parseInt(st.nextToken());
				
				if(map[n][m] == 2) {
					start_x = n;
					start_y = m;
				}
			}
		}
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		QX.add(start_x);
		QY.add(start_y);
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			
			for(int mx = 0; mx < move_x.length; mx++) {
				
				int go_x = X + move_x[mx];
				int go_y = Y + move_y[mx];
				
				
				if(go_x >= 0 && go_y >= 0 && go_x < N && go_y < M) {
					if(check[go_x][go_y] != 1 && map[go_x][go_y] == 1) {
						QX.add(go_x);
						QY.add(go_y);
						check[go_x][go_y] = 1;
						
						result[go_x][go_y] = result[X][Y] + 1;
					}
				}
				
				
			}
		}
		
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++) {
				
				if(result[n][m] == 0 && map[n][m] != 0 && map[n][m] != 2)
					System.out.print(-1 + " ");
				
				else
					System.out.print(result[n][m] + " ");
			}
			System.out.println();
		}

	}

}
