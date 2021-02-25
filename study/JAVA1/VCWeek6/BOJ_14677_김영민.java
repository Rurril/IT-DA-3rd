import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class BOJ_14677_김영민 {

	static int N;
	static boolean[][] eaten;
	static String[] medicine;
	static Queue<Pointer> q = new LinkedList<>();
	static String[] time = { "B", "L", "D" };

	static class Pointer {
		int left;
		int right;
		int time;

		Pointer(int left, int right, int time) {
			this.left = left;
			this.right = right;
			this.time = time;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		medicine = br.readLine().split("");
		eaten = new boolean[3 * N + 1][3 * N + 1];
		bfs();
	}

	static void bfs() {
		eaten[0][0] = true;
		q.add(new Pointer(0, 0, 0));

		int pill = -1;
		while (!q.isEmpty()) {
			int size = q.size();
			while (size > 0) {
				size--;
				Pointer pointer = q.poll();
				int left = pointer.left;
				int right = pointer.right;
				int now = pointer.time;
				if (left + right < 3 * N) {
					if (medicine[left].equals(time[now % 3]) && !eaten[left + 1][right]) {
						q.add(new Pointer(left + 1, right, now + 1));
						eaten[left + 1][right] = true;
					}
					if (medicine[3 * N - 1 - right].equals(time[now % 3]) && !eaten[left][right + 1]) {
						q.add(new Pointer(left, right + 1, now + 1));
						eaten[left][right + 1] = true;
					}
				}
			}
			pill++;
		}
		System.out.println(pill);
	}
}
