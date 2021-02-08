import java.util.*;

public class 1389_KevinBacon_Step {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		ArrayList<Integer> Kevin[] = new ArrayList[N+1];
		for(int n = 0; n <= N; n++)
			Kevin[n] = new ArrayList();
		
		for(int m = 0; m < M; m++) {
			
			int A = input.nextInt();
			int B = input.nextInt();
			
			Kevin[A].add(B);
			Kevin[B].add(A);
		}
		
		ArrayList<Integer> answer = new ArrayList<>();
		
		Queue<Integer> find = new LinkedList<>();
		
		for(int i = 1; i <= N; i++) {
			
			int check[] = new int[N+1];
			int result[] = new int[N+1];
			
			check[i] = 1;
			
			//Queue<Integer> find = new LinkedList<>();
			find.add(i);
			int count = 0;
			
			while(!find.isEmpty()) {
				
				int F = find.poll();
				
				for(int f = 0; f < Kevin[F].size(); f++) {
					
					if(check[Kevin[F].get(f)] == 1)
						continue;
					
					result[Kevin[F].get(f)] = result[F] + 1;
					count = count + result[Kevin[F].get(f)];
					
					check[Kevin[F].get(f)] = 1;
					find.add(Kevin[F].get(f));
				}
			}
			
			answer.add(count);
		}
		
		int min = answer.get(0);
		int final_answer = 1;
		
		for(int a = 1; a < answer.size(); a++) {
			
			if(min > answer.get(a)) {
				min = answer.get(a);
				final_answer = a+1;
			}
				
		}
		
		System.out.println(final_answer);

	}

}
