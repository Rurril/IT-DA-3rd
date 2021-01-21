package itda_2020;

import java.util.Scanner;

public class BOJ_14226_박소현 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); 
		int S = scan.nextInt();
		int DP[] = new int[2001];
		
		for (int i=0;i<2001;i++) {
			DP[i] = 10000;
		}
		DP[1] = 0;
	
		for (int i = 1; i <= 1000; ++i) {
			for (int j = 2; j * i <= 1000; ++j) {
				//System.out.println("here");
				DP[j * i] = Math.min(DP[j * i], DP[i] + j);
			}
		    for (int j = 1000; j >= 2; --j) {
		        DP[j] = Math.min(DP[j], DP[j + 1] + 1);
		    }
		}
		System.out.println(DP[S]);
		
	/*	for (int i=0;i<2000;i++) {
			System.out.print(DP[i]+" ");
		}
			*/
	}

	

}

/*	
 
 int pin = 1;
int tmp = 0;
 while (DP[S]==0) {
if(pin+tmp>1000) DP[pin+tmp] = DP[pin]+1;
DP[pin*2] = DP[pin] + 1;
if (pin-1>0) DP[pin-1] = DP[pin]+1;

}
*/