import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class RainFall {

	public static void main(String[] args) throws IOException {
		// 왼, 오에서 최대값 구하고 그 둘 중에 작은거 선택
		ArrayList<Integer> list = new ArrayList<>();
		
		int temp;
		int rain;
		int rain_sum = 0;
		int left_max = 0;
		int right_max;
		int H;
		int W;
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < W; i++) {
			list.add(Integer.parseInt(st.nextToken()));
		}
	
		for(int i = 1; i < W - 1; i++) {
			right_max = 0;
			list.get(i);
			
			left_max = Math.max(list.get(i-1), left_max);
			
			for(int j = i + 1; j < W; j++) {
				right_max = Math.max(list.get(j), right_max);
			}
			
			temp = Math.min(left_max, right_max);
			rain = temp - list.get(i);
			
			if(rain > 0) {
				rain_sum = rain_sum + rain;
			}
		}
		
		System.out.println(rain_sum);
	}

}
