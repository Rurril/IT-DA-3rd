import java.util.*;

public class 18352_특정거리의도시찾기 {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		int K = input.nextInt();
		int X = input.nextInt();
		
		/**
		 * 2차원 배열이 메모리초과가 이렇게 많이 되는줄 몰랐다...
		 * 선언 자체만으로도 메모리초과가 엄청나다
		 */
		//int map[][] = new int[N+1][N+1];
		int check[] = new int[N+1];
		int result[] = new int[N+1];
		
		ArrayList<Integer> maplist[] = new ArrayList[N+1];
		
		for(int i = 0; i <= N; i++)
		//for(int i = 1; i <= N; i++) -> 이렇게 하면 안된다 ㅎㅎㅎ
			maplist[i] = new ArrayList();
		
		for(int m = 0; m < M; m++) {
			
			int A = input.nextInt();
			int B = input.nextInt();
			
			//map[A][B] = 1;
			
			//maplist[A] = new ArrayList();
			maplist[A].add(B);
		}
		
		Queue<Integer> City = new LinkedList<>();
		
		check[X] = 1;
		City.add(X);

		while(!City.isEmpty()) {
			
			int C = City.poll();
			
			for(int i = 0; i < maplist[C].size(); i++) {
				
				int go_city = maplist[C].get(i);
				
				if(check[go_city] == 0) {
					City.add(go_city);
					check[go_city] = 1;
					result[go_city] = result[C] + 1;
				}
			}
		}
		
		ArrayList<Integer> answer = new ArrayList<>();
		for(int i = 1; i <= N; i++) {
			//if(check[i] == K)
			if(result[i] == K)
				answer.add(i);
		}
		
		if(answer.size() == 0)
			System.out.println(-1);
		
		else {
			
			Collections.sort(answer);
			for(int a = 0; a < answer.size(); a++) {
				System.out.println("정답은 " + answer.get(a));
			}
		}
	}

}
