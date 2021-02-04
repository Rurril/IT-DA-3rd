package itda_2020;

import java.util.*;

public class BOJ_1389_박소현 {
	public static int N, M;
	public static int Map[][];
	static boolean visited[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		N = scan.nextInt();
		M = scan.nextInt();
		Map = new int[101][101];
		visited = new boolean[101];

		for (int i=0;i<M;i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			Map[x][y] = 1;
			Map[y][x] = 1;
		}
		
		for (int i=1;i<=N;i++) {
			bfs(i);
		}
	}
	public static void bfs(int input) {
		Queue<xy> queue = new LinkedList<>();
		xy first = new xy(input,0);
		queue.add(first);
		visited[input] = true;
		while(!queue.isEmpty()) {
			xy next = queue.poll();
			int x = next.x;
			int y = next.y;
			for (int i=0;i<=N;i++) {
				if(0<=x&&x<N&&0<=y&&y<N&&!visited[i]&&Map[x][i]==1) {				
					queue.add(new xy(i,y+1));
					visited[i] = true;

				}
			}
		}
	}
	class xy {
		int x;
		int y;
		xy (int x, int y){
			this.x = x;
			this.y = y;
		}
	}
}
