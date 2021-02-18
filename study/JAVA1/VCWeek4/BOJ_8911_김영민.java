import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ_8911_김영민 {

	static int[] offsetx = { 0, -1, 0, 1 }; // 0:up 1:left 2:down 3:right
	static int[] offsety = { 1, 0, -1, 0 };

	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int T = Integer.parseInt(br.readLine());

		for (int i = 0; i < T; i++) {
			String command = br.readLine();
			int currentX = 0, currentY = 0;
			int maxX = 0, maxY = 0;
			int minX = 0, minY = 0;

			int direction = 0;
			for (int j = 0; j < command.length(); j++) {
				char now = command.charAt(j);

				if (now == 'F') {
					currentX += offsetx[direction];
					currentY += offsety[direction];
					maxX = Math.max(maxX, currentX);
					maxY = Math.max(maxY, currentY);
					minX = Math.min(minX, currentX);
					minY = Math.min(minY, currentY);
				} else if (now == 'B') {
					currentX -= offsetx[direction];
					currentY -= offsety[direction];
					maxX = Math.max(maxX, currentX);
					maxY = Math.max(maxY, currentY);
					minX = Math.min(minX, currentX);
					minY = Math.min(minY, currentY);
				} else if (now == 'L') {
					if (direction == 0) {
						direction = 1;
					} else if (direction == 1) {
						direction = 2;
					} else if (direction == 2) {
						direction = 3;
					} else if (direction == 3) {
						direction = 0;
					}
				} else if (now == 'R') {
					if (direction == 0) {
						direction = 3;
					} else if (direction == 3) {
						direction = 2;
					} else if (direction == 2) {
						direction = 1;
					} else if (direction == 1) {
						direction = 0;
					}
				}
			}
			bw.write((maxX - minX) * (maxY - minY) + "\n");
		}
		bw.flush();
	}
}
