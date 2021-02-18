import java.util.Scanner;

public class 5212_배열복사정말힘드네? {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		/**
		 * 망할 배열복사
		 * seom.clone()해줘도 얕은복사가 된다. 분명 블로그에서는 깊은복사라고했는데 왜 안되는지모르겠다 화가난다
		 * 내가 잘못쓴건가
		 * 
		 * 아무튼 배열복사 때려치고 그냥 배열두개로 다 넣어줬다. ㅜㅜ
		 */
		char seom[][] = new char[N+2][M+2];
		char seom_copy[][] =  new char[N+2][M+2];
		
		//1. 처음에는 다 .으로 채우기
		for(int i = 0; i < seom.length; i++) 
			for(int j = 0; j < seom[i].length; j++)
				seom[i][j] = '.';
		
		
		//2. 예제 입력 받기
		for(int i = 1; i <= N; i++) {
			
			String S = input.next();
			
			for(int j = 1; j <= M; j++) {
				seom[i][j] = S.charAt(j-1);
				seom_copy[i][j] = seom[i][j];
			}
				
		}
		
		int move_x[] = {0, 0, 1, -1};
		int move_y[] = {1, -1, 0, 0};
		
		/**
		 * start, end좌표를 주어서 50년후의 줄어든 섬의 길이만큼을 출력하도록 하였다.
		 */
		int start_x = N;
		int start_y = M;
		
		int end_x = 0;
		int end_y = 0;
		
		for(int i = 1; i <= N; i++) {
			
			for(int j = 1; j <= M; j++) {
				
				if(seom[i][j] == 'X') {
					
					int count = 0;
					
					for(int mx = 0; mx < move_x.length; mx++) {
						
						int go_x = i + move_x[mx];
						int go_y = j + move_y[mx];
						
						if(seom[go_x][go_y] == '.') 
							count++;
					}
					
					if(count >= 3)//count개수를 세줘서 바다가 3개, 4개와 접해있으면 바다로 바꾸도록 하였다.
						seom_copy[i][j] = '.';
					
					else { // 그대로 X로 남아있다면 그 좌표값을 저장하도록 하였다.
						start_x = Math.min(start_x, i);
						start_y = Math.min(start_y, j);
						
						end_x = Math.max(end_x, i);
						end_y = Math.max(end_y, j);
					}
				}
			}
		}
		
		//3. 50년후의 지도 출력
		for(int i = start_x; i <= end_x; i++) {
			for(int j = start_y; j <= end_y; j++) {
				System.out.print(seom_copy[i][j]);
			}
			System.out.println();
		}
	}
}
