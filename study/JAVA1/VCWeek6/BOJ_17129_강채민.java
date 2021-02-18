import java.util.*;

public class 17129_윌리암슨수액빨이딱따구리 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		int map[][] = new int[N][M];
		int check[][] = new int[N][M];
		
		int move_x[] = {-1, 1, 0, 0};
		int move_y[] = {0, 0, -1, 1};
		
		int start_x = 0;
		int start_y = 0;
		
		for(int n = 0; n < N; n++) {
			
			String S = input.next();
			
			for(int m = 0; m < M; m++) {
				map[n][m] = S.charAt(m) - '0';
				
				if(map[n][m] == 2) { // 시작 좌표 저장
					start_x = n;
					start_y = m;
				}
			}
				
		}
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		Queue<Integer> Qcount = new LinkedList<>();
		
		QX.add(start_x);
		QY.add(start_y);
		Qcount.add(0);
		check[start_x][start_y] = 1;
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			int C = Qcount.poll();
			
			if(map[X][Y] == 3 || map[X][Y] == 4 || map[X][Y] == 5) {
				System.out.println("TAK");
				System.out.println(C);
				return;
			}
			
			for(int mx = 0; mx < move_x.length; mx++) {
				
				int go_x = X + move_x[mx];
				int go_y = Y + move_y[mx];
				
				if(go_x < 0 || go_y < 0 || go_x >= N || go_y >= M)
					continue;
				
				if(map[go_x][go_y] == 1 || check[go_x][go_y] == 1)
					continue;
				
				QX.add(go_x);
				QY.add(go_y);
				Qcount.add(C+1);
				check[go_x][go_y] = 1;
			}
		}
		
		System.out.println("NIE");

	}

}
