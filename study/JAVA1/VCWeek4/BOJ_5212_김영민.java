import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_5212_김영민 {

	static int[] offsetx = { 0, -1, 0, 1 };
	static int[] offsety = { 1, 0, -1, 0 };

	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] temp = br.readLine().split(" ");
		int R = Integer.parseInt(temp[0]);
		int C = Integer.parseInt(temp[1]);

		char[][] map = new char[12][12];
		char[][] afterMap = new char[12][12];

		for (int i = 1; i <= R; i++) {
			temp = br.readLine().split("");
			for (int j = 0; j <= C + 1; j++) {
				if (j == 0) {
					map[i][j] = '.';
				} else if (j == C + 1) {
					map[i][j] = '.';
				} else {
					map[i][j] = temp[j - 1].charAt(0);
				}

				afterMap[i][j] = map[i][j];

				map[0][j] = '.';
				map[R + 1][j] = '.';
				afterMap[0][j] = '.';
				afterMap[R + 1][j] = '.';
			}
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				int count = 0;
				if (map[i][j] == 'X') {
					for (int k = 0; k < 4; k++) {
						int ay = i + offsety[k];
						int ax = j + offsetx[k];
						if (map[ay][ax] == '.') {
							count++;
						}
					}
				}
				if (count >= 3) {
					afterMap[i][j] = '.';
				}
			}
		}

		int minX = 11, maxX = 0, minY = 11, maxY = 0;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (afterMap[i][j] == 'X') {
					maxX = Math.max(maxX, j);
					maxY = Math.max(maxY, i);
					minX = Math.min(minX, j);
					minY = Math.min(minY, i);
				}
			}
		}

		for (int i = minY; i <= maxY; i++) {
			for (int j = minX; j <= maxX; j++) {
				System.out.print(afterMap[i][j]);
			}
			System.out.println();
		}
	}
}
