package itda_2020;

import java.util.Scanner;

public class BOJ_11559_박소현 {
	static int[] dx = {-1, 0, 1, 0}; 
	static int[] dy = {0, 1, 0, -1};
	static boolean visited[][] ;
	static int count = 0;
	static int result = 0;
	static char input[][] = new char[12][6];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		visited = new boolean[12][6];
		Scanner scan = new Scanner(System.in);
		for (int i=0;i<12;i++) {
			String S = scan.next();
			char[] arr = S.toCharArray();
			for (int j=0;j<6;j++) {
				if (arr[j]=='R') input[i][j] = 'R'; 
				else if (arr[j]=='G') input[i][j] = 'G'; 
				else if (arr[j]=='B') input[i][j] = 'B'; 
				else if (arr[j]=='P') input[i][j] = 'P'; 
				else if (arr[j]=='Y') input[i][j] = 'Y'; 
			}
		}
		
		for (int i=0;i<12;i++) {
			for (int j=0;j<6;j++) {
				if (!visited[i][j]) {
					dfs(i,j,input[i][j]);
					System.out.println(count);
					if (count>=4) result ++;
					count = 0;
				}
			}
		
		}
		
	/*	for (int i=0;i<12;i++) {
			for (int j=0;j<6;j++) {
				System.out.print(input[i][j]+" ");
			}
			System.out.println("");
		}
	*/	
		System.out.println(result);
		
	}
	public static void dfs (int x,int y,char color) {
		count ++;
		for (int i = 0; i<4;i++) {	
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (0<=nextX && 0<=nextY && nextX<6&& nextY<12&&!visited[nextX][nextY]&&input[nextX][nextY]==color) {
				//System.out.printf("%d	%d\n",nextX,nextY);
				visited[nextX][nextY] = true; 
				//System.out.printf("x y %d	%d\n",nextX,nextY);
				//System.out.println(count);
				dfs(nextX,nextY,input[nextX][nextY]);
			}
		}
	}

}
