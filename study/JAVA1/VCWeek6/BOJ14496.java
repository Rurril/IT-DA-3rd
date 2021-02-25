package 백준공부;
import java.util.*;


public class BOJ14496 {
	static int a;
	static int b;
	static int check[];
	static ArrayList map[];
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		a = scan.nextInt();
		b = scan.nextInt();
		int N = scan.nextInt();
		int M = scan.nextInt();
		check = new int[N+1];
		map = new ArrayList[N+1];
		
		for(int i = 0; i <= N; i++) {
			map[i] = new ArrayList(); }
		for (int i=0;i<M;i++) {
			int A = scan.nextInt();
			int B = scan.nextInt();
			map[A].add(B);
			map[B].add(A);
		}
		bfs();
	}
	public static void bfs() {
		Queue<Integer> queue = new LinkedList<>();
		queue.add(a);
		while(!queue.isEmpty()) {
			int pin = queue.poll();
			
			if (pin == b) {
				System.out.print(check[pin]);
				return; 
			}
			
			for (int i=0;i<map[pin].size();i++) {
				if(check[map[pin].get(i)]==0) {				
						queue.add(map[pin].get(i));
						check[map[pin].get(i)] = check[pin] + 1;
				}
			}
		}
		System.out.println("-1");
	}
}
