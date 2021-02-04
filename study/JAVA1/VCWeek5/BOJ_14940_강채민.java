import java.util.*;

public class 14940_Easy_Shortest_Distance {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		int map[][] = new int[N][M];
		int result[][] = new int[N][M];
		int check[][] = new int[N][M];
		
		int move_x[] = {1, -1, 0, 0};
		int move_y [] = {0, 0, 1, -1};
		
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++) {
				map[n][m] = input.nextInt();
				result[n][m] = -1;
			}
		}
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		
		//Arrays.fill(result, -1);
		
		QX.add(0);
		QY.add(0);
		check[0][0] = 1;
		result[0][0] = 0;
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			
			for(int mx = 0; mx < move_x.length; mx++) {
				
				int go_x = X + move_x[mx];
				int go_y = Y + move_y[mx];
				
				if(go_x < 0 || go_y < 0 || go_x >= N || go_y >= M)
					continue;
				
				if(check[go_x][go_y] == 1)
					continue;
				
				if(map[go_x][go_y] == 0) {
					result[go_x][go_y] = 0;
					continue;
				}
				
				QX.add(go_x);
				QY.add(go_y);
				check[go_x][go_y] = 1;
				
				result[go_x][go_y] = result[X][Y] + 1;
			}
		}
		
		for(int n = 0; n < N; n++) {
			for(int m = 0; m < M; m++) {
				System.out.print(result[n][m] + " ");
			}
			System.out.println();
		}

	}

}
