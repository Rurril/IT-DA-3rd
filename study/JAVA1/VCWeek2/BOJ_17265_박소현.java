package itda_2020;
import java.util.Scanner;
public class BOJ_17265_박소현 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); 
		int N = scan.nextInt();
		char input[][] = new char[N+1][N+1];
		int DP[][] = new int[N+1][N+1];
		scan.nextLine();
		for (int i=1;i<=N;i++) {
			char[] tmp= scan.nextLine().replaceAll(" ","").toCharArray();
			//System.out.println(tmp.length);
			for (int j=1;j<=N;j++) {
				input[i][j] = tmp[j-1];
			}
		}
		DP[1][1] = Character.getNumericValue(input[1][1]);
		
		for (int i=1;i<=N;i++) {
			for (int j=1;j<=N;j++) {
				
			}
		}
	/*	for (int i=0;i<=N;i++) {
			for (int j=0;j<=N;j++) {
				System.out.print(input[i][j]+" ");
			}
			System.out.println();
		}
		*/
	}

}

