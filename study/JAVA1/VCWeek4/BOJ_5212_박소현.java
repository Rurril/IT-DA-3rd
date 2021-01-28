package itda_2020;

import java.util.Scanner;

public class BOJ_5212_박소현 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		int R = scan.nextInt();
		int C = scan.nextInt();
		String Map[][] = new String[12][12];
		String result[][] = new String[12][12];
		for (int i=1;i<R+1;i++) {
			String tmp = scan.next();
			for (int j=1;j<C+1;j++) {
				Map[i][j] = String.valueOf(tmp.charAt(j-1));
			}
		}
		for (int i=0;i<=R+1;i++) {
			for (int j=0;j<=C+1;j++) {
				if (i==0||i==R+1) Map[i][j] =".";
				if (j==0||j==C+1) Map[i][j] =".";
			}
		}
		
	/*
		for (int i=0;i<=R+1;i++) {
			for (int j=0;j<=C+1;j++) {
				System.out.printf("%s ",Map[i][j]);
			}
			System.out.println();
		}
	*/	
	
		
		for (int i=1;i<=R;i++) {
			for (int j=1;j<=C;j++) {
				int count = 0;
				if (Map[i][j]==".") continue;
				if(Map[i-1][j]==".") count++;
				if(Map[i+1][j]==".") count++;
				if(Map[i][j-1]==".") count++;
				if(Map[i][j+1]==".") count++;
				if (count>=3) result[i][j] = ".";
			}
		}
	
		/*
		for (int i=0;i<=R+1;i++) {
			for (int j=0;j<=C+1;j++) {
				System.out.printf("%s ",result[i][j]);
			}
			System.out.println();
		}
		*/
	}

}
