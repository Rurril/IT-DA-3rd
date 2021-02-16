import java.util.Scanner;

public class DFS_14500_테트로미노_강 {

	static int N;
	static int M;
	
	static int map[][];
	static int check[][];
	static int answer = 0;
	
	static int move_x[] = {-1, 1, 0, 0};
	static int move_y[] = {0, 0, 1, -1};

	public static void main(String[] args) {
		
		/**
		 * https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14500-%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8
		 * 참고했습니다
		 * 
		 * 그리고 우리 팀장님코드 참고했습니다 
		 * https://github.com/Rurril/IT-DA-3rd/blob/master/study/JAVA1/VCWeek4/BOJ_14500_%EA%B9%80%EC%98%81%EB%AF%BC.java
		 * 
		 * dfs로 모든 좌표를 탐색하는것은 아직도 어색하네요..
		 * 아무튼 드디어 코드를 올리게 되었습니다!
		 * 늦어서 죄송합니다!
		 */
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		M = input.nextInt();
		
		map = new int[N][M];
		check = new int[N][M];

		for(int n = 0; n < N; n++) 
			for(int m = 0; m < M; m++)
				map[n][m] = input.nextInt();
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				
				check[i][j] = 1;
				dfs(i, j, 1, map[i][j]);
				other(i, j);
				check[i][j] = 0;
			}
		}
		
		System.out.println(answer);
	}
	
	static void dfs(int x, int y, int count, int result) {
		
		if(count == 4) {
			answer = Math.max(answer, result);
			return;
		}
		
		for(int mx = 0; mx < move_x.length; mx++) {
			
			int go_x = x + move_x[mx];
			int go_y = y + move_y[mx];
			
			if(go_x < 0 || go_y < 0 || go_x >= N || go_y >= M
					|| check[go_x][go_y] == 1)
				continue;
			
			check[go_x][go_y] = 1;
			dfs(go_x, go_y, count+1, result+map[go_x][go_y]);
			check[go_x][go_y] = 0;
		}
	}
	
	static void other(int x, int y) {
		
		int sum = 0;
		
		//1. ㅗ 
		if(x >= 0 && x+1 < N && y-1 >= 0 && y+1 < M) {
			sum = map[x][y] + map[x+1][y-1] + map[x+1][y] + map[x+1][y+1];
			answer = Math.max(answer, sum);
		}
		
		//2. ㅜ
		if(x >= 0 && x+1 < N && y >= 0 && y+2 < M) {
			sum = map[x][y] + map[x][y+1] + map[x][y+2] + map[x+1][y+1];
			answer = Math.max(answer, sum);
		}
		
		//3.ㅏ
		if(x >= 0 && x+3 < N && y >= 0 && y+1 < M) {
			sum = map[x][y] + map[x+1][y] + map[x+2][y] + map[x+1][y+1];
			answer = Math.max(answer, sum);
		}
		
		//4. ㅓ
		if(x-1 >= 0 && x+1 < N && y >= 0 && y+1 < M) {
			sum = map[x][y] + map[x-1][y+1] + map[x][y+1] + map[x+1][y+1];
			answer = Math.max(answer, sum);
		}
	}

}
