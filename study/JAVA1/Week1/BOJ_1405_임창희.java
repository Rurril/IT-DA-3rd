package level1;
// 왔다온 길은 다시 못간다.
//N번 움직인다.(N<=14, 자연수)
//모든 확률은 100보다 작거나 같은 자연수 또는 0이다. 
//확률을 다 더하면 100이다.
//동 ,서, 남, 북으로 움직일 수 있다.
//확률을 구하는 프로그램

import java.util.Scanner;

public class CrazeRobot {
	static int N;
	static double []persent = new double[4];
	static int[] rx = {1,-1,0,0};
	static int[] ry = {0,0,1,-1};
	static boolean[][] check;
	static double answer=0.0;

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		double result=0;
		for(int p=0;p<persent.length;p++) {
			persent[p] = sc.nextInt()*0.01;
		}
		check = new boolean[29][29];
		check[14][14]=true;
		result = DFS(0,14,14,1);
		System.out.println(result);
	}
	// n=횟수, dx = x의 위치,dy = y의 위치, p = 확률
	static double DFS(int n, int dx, int dy, double p) {
		if(n==N) {
			answer +=p;
			return answer;
		} 
		for(int i=0;i<persent.length;i++) {
			if(!(check[dx+rx[i]][dy+ry[i]])) {
				check[dx+rx[i]][dy+ry[i]]=true;
				DFS(n+1,dx+rx[i],dy+ry[i],persent[i]*p);
				check[dx+rx[i]][dy+ry[i]]=false;
			}else {
				continue;
			}
		}
		return answer;
	}
}
