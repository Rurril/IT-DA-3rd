package BaekJoon_BFS_DFS;

import java.util.*;

public class BFS_16973_직사각형탈출 {

	public static class rectan {
		int x;
		int y;
		int count;
		
		public rectan(int x, int y, int count) {
			this.x = x;
			this.y = y;
			this.count = count;
		}
	}
	
	static int H;
	static int W;
	static int N;
	static int M;
	
	static int map[][];
	
	public static void main(String[] args) {
			
			/**
			 * 아....
			 * https://docs16.tistory.com/92 
			 * 참고했습니다
			 * 
			 * 일단 bfs를 다 돌기전에 이미 가지 못하는곳을 체크해줘야하는구나
			 * 
			 * 이상하게 java11로 하면 틀리고 java8로 하면 맞는..
			 */
			
			Scanner input = new Scanner(System.in);
			
			N = input.nextInt();
			M = input.nextInt();
			
			map = new int[N+1][M+1];
			int check[][] = new int[N+1][M+1];
			
			for(int n = 1; n <= N; n++) {
				for(int m = 1; m <= M; m++) {
					map[n][m] = input.nextInt();
				}
			}
			
			H = input.nextInt();
			W = input.nextInt();
			
			int start_x = input.nextInt();
			int start_y = input.nextInt();
			int end_x = input.nextInt();
			int end_y = input.nextInt();
			
			/**
			 * 1. 일단 bfs를 돌기 전에 갈 수 없는 곳부터 파악해야 한다.
			 */
			
			for(int i = 1; i <= N; i++) {
				for(int j = 1; j <= M; j++) {
					
					if(map[i][j] == 1) {
						
						for(int ii = i; ii > i - H; ii--) {
							
							if(ii < 0)
								break;
							
							for(int jj = j; jj > j - W; jj--) {
								
								if(jj < 0)
									break;
								
								check[ii][jj] = 1;
							}
						}
					}
				}
			}
			
			Queue<rectan> QQ = new LinkedList<rectan>();
			
			int move_x[] = {1, -1, 0, 0};
			int move_y [] = {0, 0, 1, -1};
			
			check[start_x][start_y] = 1;
			
			QQ.add(new rectan(start_x, start_y, 0));
			
			int min = -1;
			
			while(!QQ.isEmpty()) {
				
				rectan R = QQ.poll();
				
				int X = R.x;
				int Y = R.y;
				int C = R.count;
				
				if(X == end_x && Y == end_y) {
					/*
					min = Math.min(min, C);
					continue;
					*/
					//System.out.println(C);
					//return;
					min = C;
					break;
				}
				
				for(int mx = 0; mx < move_x.length; mx++) {
					
					int go_x = X + move_x[mx];
					int go_y = Y + move_y[mx];
					
					if(go_x < 1 || go_y < 1 || go_x >= N+1 || go_y >= M+1) 
						continue;
					if(check[go_x][go_y] == 1 || map[go_x][go_y] == 1)
						continue;
					
					
					check[go_x][go_y] = 1;
					
					if(check(go_x, go_y)) {
						QQ.add(new rectan(go_x, go_y, C+1));
					}
				}
			}
			
			System.out.println(min);
	}
	
	public static boolean check(int x, int y) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (x + i > N || y + j > M || map[x + i][y + j] == 1) {
					return false;
				}
			}
		}
		return true;
	}


}
