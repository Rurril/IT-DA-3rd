import java.util.*;

public class 5212_Global_Warming {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		//String seom[][] = new String[N+2][M+2];
		char seom[][] = new char[N+2][M+2];
		
		/**
		 * Arrays.fill(seom, ".");
		 * 안되네 ㅎㅎ..
		 */
		
		//1. 처음에는 다 .으로 채우기
		for(int i = 0; i < seom.length; i++)
			for(int j = 0; j < seom[i].length; j++)
				//seom[i][j] = ".";
				seom[i][j] = '.';
		
		//2. 예제 입력 받기
		for(int i = 1; i <= N; i++) {
			
			String S = input.next();
			//seom[i] = S.split("");
			
			for(int j = 1; j <= M; j++)
				seom[i][j] = S.charAt(j-1);
		}
		
		
		for(int i = 0; i < N+2; i++) {
			for(int j = 0; j < M+2; j++) {
				System.out.print(seom[i][j]);
			}
			System.out.println();
		}
		
		int move_x[] = {0, 0, 1, -1};
		int move_y[] = {1, -1, 0, 0};
		
		int start_x = N;
		int start_y = M;
		
		char seom_copy[][] = seom;
		
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				
				/*
				if(seom[i][j] == '.')
					continue;
				*/
				if(seom[i][j] == 'X') {
					int count = 0;
					
					for(int mx = 0; mx < move_x.length; mx++) {
						
						int go_x = i + move_x[mx];
						int go_y = j + move_y[mx];
						
						if(seom[go_x][go_y] == '.') 
							count++;
					}
					
					if(count >= 3)
						seom_copy[i][j] = '.';
					
					else {
						start_x = Math.min(start_x, i);
						start_y = Math.min(start_y, j);
					}
				}
			}
		}
		
		System.out.println(start_x + " " + start_y);
		
		for(int i = 0; i < seom.length; i++) {
			for(int j = 0; j < seom[i].length; j++) {
				System.out.print(seom[i][j]);
			}
			System.out.println();
		}

	}

}
