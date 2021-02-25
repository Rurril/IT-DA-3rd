package 백준공부;

public class BOJ17129 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		int M = scan.nextInt();
		int map[][] = new int[N][M];
		int check[][] = new int[N][M];
		int dy[] = {0,0,1,-1};
		int dx[] = {1,-1,0,0};
		int x = 0;
		int y = 0;
		for (int i=0;i<N;i++) {
			String S = scan.next();
			for (int j=0;j<M;j++) {
				map[i][j] = S.charAt(j) - '0';
				if (map[i][j] ==2) {
					x = N; 
					y = M;
				}
			}
	}
	public static int bfs() {
		
	}
		
}
	//이것도 그냥 ,,,bfs 문제,,, 같은데 
//그냥 세마리가 각자 갈길 가고 그 세개 중에 최소값을 구해보겠ㄷ가 저의 풀이입니다 ...!
