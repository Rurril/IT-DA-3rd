import java.util.*;

public class 17265_나의인생에는수학과함께진 {
	
	static int N;
	static char map[][];
	static int check[][];
	
	static int max = Integer.MIN_VALUE;
	static int min = Integer.MAX_VALUE;
	
	static int move_x[] = {0, 1};
	static int move_y[] = {1, 0};

	public static void main(String[] args) {
		
		/**
		 * bfs로 풀려다가 안되서 
		 * dp로 풀려다가 너무 복잡해서
		 * 결국 dfs로 했는데 ^_ㅜ
		 * 진짜 오랜만에 문제보고 눈물날뻔..
		 * 
		 * https://minhamina.tistory.com/49
		 * 
		 */
		
		Scanner input = new Scanner(System.in);
		
		N = input.nextInt();
		
		/*
		String map[][] = new String[N][N];
		int check[][] = new int[N][N];
		*/
		
		//char map[][] = new char[N+1][N+1];
		map = new char[N][N];
		check = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				map[i][j] = input.next().charAt(0);
			}
		}
		
		/*
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}
		*/

		check[0][0] = 1;
		dfs(0, 0, map[0][0] - '0', map[0][0]);
		
		System.out.println(max + " " + min);
	}
	
	public static void dfs(int x, int y, int num, char op) {
		
		/*
		 * (n, n까지 다 확인해야하기 때문에 밑에 계산까지 다 해야한다.
		 * 
		if(x == N-1 && y == N-1) {
			max = Math.max(max, num);
			min = Math.min(min, num);
			
			return;
		}
		*/
		
		int now = map[x][y] - '0';
		
		//========================================================
		if(now >= 0 && now <= 5) { // 숫자라면
			
			if(op == '+') 
				num = num + now;
			
			else if(op == '-') 
				num = num - now;
			
			else if(op == '*') 
				num = num * now;
			
		}
		
		else  // 연산자인경우
			op = map[x][y];
		//========================================================
		
		if(x == N-1 && y == N-1) {
			max = Math.max(max, num);
			min = Math.min(min, num);
			
			return;
		}
		
		for(int mx = 0; mx < move_x.length; mx++) {
			
			int go_x = x + move_x[mx];
			int go_y = y + move_y[mx];
			
			if(go_x < 0 || go_y < 0 || go_x >= N || go_y >= N)
				continue;
			
			if(check[go_x][go_y] == 1)
				continue;
			
			check[go_x][go_y] = 1;
			dfs(go_x, go_y, num, op);
			check[go_x][go_y] = 0;
		}
	}

}
