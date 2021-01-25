import java.util.*;

public class 14891_그냥구현이였어.. {
	
	static int check[];
	static ArrayList <Integer> Gear[] = new ArrayList[5];

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		/**
		 * https://github.com/Rurril/IT-DA-3rd/blob/master/study/Python/VCWeek3/BOJ_14891_%EC%9A%B0%EC%B0%BD%EC%99%84.py
		 * 파이썬팀 코드 참고했습니다..
		 * 
		 * 간단 구현인데 알바하면서 고민하니까 하..나..도... 머리에 생각이 나질 않았네요..
		 * 뭔가 알고리즘이 있을거같아서 그냥 막 if문으로 때려넣으면 안되지 않을까 싶었는데 되네요 ㅎㅎㅎㅎ
		 * 
		 * 재귀함수를 이용해서 계속 한번에 쭉 돌려줘야 더 효율적이고 코드도 깔끔한거같습니다
		 * 파이썬팀 (우창완님..)감사합니다 새해 복 많이 받으시구 제가 정말 감사드려요..
		 */
		
		
		for(int i = 1; i <= 4; i++) {
			
			String S = input.next();
			
			Gear[i] = new ArrayList();
			
			for(int j = 0; j < S.length(); j++)
				Gear[i].add(S.charAt(j) - '0');
		}
		
		int K = input.nextInt();
		
		for(int k = 0; k < K; k++) {
			
			int N = input.nextInt(); // 번호
			int D = input.nextInt();
			
			check = new int[5];
			rotate(N, D);
		}
		
		double sum = 0;
		
		for(int s = 1; s < Gear.length; s++) {
    
			if(Gear[s].get(0).equals(0))
				sum = sum + 0;
			
			else
				sum = sum + (Math.pow(2, s-1));
		}
		
		System.out.println((int)sum);

	}
	
	static void rotate(int N, int D) {
		
		check[N] = 1;
		
		if(N == 2 || N == 3) {
			
			if(Gear[N].get(2) != Gear[N+1].get(6)) {
				if(check[N+1] != 1) {
					//int dir = (D == 1) ? -1 : 1;
					rotate(N+1, (D == 1) ? -1 : 1);
				}
			}
			
			if(Gear[N].get(6) != Gear[N-1].get(2)) {
				if(check[N-1] != 1) {
					rotate(N-1, (D == 1) ? -1 : 1);
				}
			}
		}
		
		else if(N == 1) {
			if(Gear[N].get(2) != Gear[N+1].get(6)) {
				if(check[N+1] != 1) {
					rotate(N+1, (D == 1) ? -1 : 1);
				}
			}
		}
		
		else if(N == 4) {
			if(Gear[N].get(6) != Gear[N-1].get(2)) {
				if(check[N-1] != 1) {
					rotate(N-1, (D == 1) ? -1 : 1);
				}
			}
		}
		
		//=====================================================
    
		if(D == 1) { // 시계방향이라면
			//int change = Gear[N].get(7);
			int change = Gear[N].remove(7);
			Gear[N].add(0, change);
		}
		
		else if(D == -1) {
			int change = Gear[N].remove(0);
			Gear[N].add(change);
		}
	}

}
