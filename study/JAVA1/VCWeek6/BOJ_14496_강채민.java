import java.util.*;

public class 14496_그대그머가되어 {

	public static void main(String[] args) {
		
		/**
		 * check 배열로 해줘도 되고 
		 * 아니면 count를 세줘도 된다.
		 * 
		 * https://github.com/Rurril/IT-DA-3rd/blob/69d638539f3b882abdc756584e3910fe0fd90eda/study/Python/VCWeek6/BOJ_14496_%EA%B9%80%EB%AF%BC%EC%84%A0.py
		 * 참고했습니다 ㅎㅎ
		 */
		
		Scanner input = new Scanner(System.in);
		
		int a = input.nextInt();
		int b = input.nextInt();
		
		int N = input.nextInt();
		int M = input.nextInt();
		
		int check[] = new int[N+1];
		
		ArrayList<Integer> maplist[] = new ArrayList[N+1];
		
		for(int i = 0; i <= N; i++)
			maplist[i] = new ArrayList();
		
		for(int m = 0; m < M; m++) {
			
			int A = input.nextInt();
			int B = input.nextInt();
			
			maplist[A].add(B);
			maplist[B].add(A);
		}
		
		Queue<Integer> Qmap = new LinkedList<>();
		//Queue<Integer> Qcount = new LinkedList<>();
		
		Qmap.add(a);
    
		while(!Qmap.isEmpty()) {
			
			int X = Qmap.poll();
			//int C = Qcount.poll();
			
			if(X == b) {
				System.out.println(check[X]);
				//System.out.println(C);
				return;
			}
			
			for(int i = 0; i < maplist[X].size(); i++) {
				
				if(check[maplist[X].get(i)] == 0) {
					
					Qmap.add(maplist[X].get(i));
					//Qcount.add(C+1);
					//check[maplist[X].get(i)] = 1;
					check[maplist[X].get(i)] = check[X] + 1;
				}
			}
		}
		
		/*
		if(answer.size() == 0)
			System.out.println(-1);
		
		else
			System.out.println(Collections.min(answer));
		*/
		System.out.println(-1);

	}

}
