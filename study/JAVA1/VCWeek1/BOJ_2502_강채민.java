import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner input = new Scanner(System.in);
		
		int D = input.nextInt();
		int K = input.nextInt();
		
		int A[] = new int[31];
		int B[] = new int[31];
		
		A[1] = 1;
		B[2] = 1;
		
		for(int i = 3; i <= 30; i++) {
			A[i] = A[i-1] + A[i-2];
			B[i] = B[i-1] + B[i-2];
		}
		
		/**
		 * 41-3A = 5B
		 */
		
		for(int i = 1; i <= 100000; i++) {
			
			if((K - A[D] * i) % B[D] == 0) {
				
				System.out.println(i);
				System.out.println((K - A[D] * i) / B[D]);
				
				break;
			}
		}
	}

}
