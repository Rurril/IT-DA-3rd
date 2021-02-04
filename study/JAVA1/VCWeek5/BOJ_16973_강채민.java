import java.util.*;

public class 16973_ {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		int map[][] = new int[N+1][M+1];
		int check[][] = new int[N+1][M+1];
		
		for(int n = 1; n <= N; n++) {
			for(int m = 1; m <= M; m++) {
				map[n][m] = input.nextInt();
			}
		}
		
		int H = input.nextInt();
		int W = input.nextInt();
		
		int start_x = input.nextInt();
		int start_y = input.nextInt();
		int end_x = input.nextInt();
		int end_y = input.nextInt();
		
		Queue<Integer> QX = new LinkedList<>();
		Queue<Integer> QY = new LinkedList<>();
		Queue<Integer> Qcount =  new LinkedList<>();
		
		int move_x[] = {1, -1, 0, 0};
		int move_y [] = {0, 0, 1, -1};
		
		QX.add(start_x);
		QY.add(start_y);
		Qcount.add(0);
		check[start_x][start_y] = 1;
		
		int min = Integer.MAX_VALUE;
		
		while(!QX.isEmpty()) {
			
			int X = QX.poll();
			int Y = QY.poll();
			int C = Qcount.poll();
			
			if(X == end_x && Y == end_y) {
				min = Math.min(min, C);
				continue;
			}
			
			for(int mx = 0; mx < move_x.length; mx++) {
				
				int go_x = X + move_x[mx];
				int go_y = Y + move_y[mx];
				
				if(go_x < 1 || go_y < 1 || go_x >= N+1 || go_y >= M+1) 
					continue;
				if(check[go_x][go_y] == 1 || map[go_x][go_y] == 1)
					continue;
				
				int flag = 0;
				
				Loop1:
				for(int i = 0; i < H; i++) {
					
					Loop2:
					for(int j = 0; j < W; j++) {
						
						if(i == 0 && j == 0)
							continue;
						
						int check_x = go_x + i;
						int check_y = go_y + j;
						
						if(check_x < 1 || check_y < 1 || check_x >= N+1 || check_y >= M+1)  {
							flag = 1;
							break Loop1;
						}
						
						/*
						if(check[check_x][check_y] == 1 || map[check_x][check_y] == 1)
							continue;
						*/
						//if(check[check_x][check_y] == 1 || map[check_x][check_y] == 1) { // 틀렸습니다
						if(map[check_x][check_y] == 1) {	
							flag = 1;
							break Loop1;
						}
							
					}
				}
				
				if(flag != 1) {
					QX.add(go_x);
					QY.add(go_y);
					Qcount.add(C+1);
					check[go_x][go_y] = 1;
				}
			}
		}
		
		System.out.println(min);
	}

}
