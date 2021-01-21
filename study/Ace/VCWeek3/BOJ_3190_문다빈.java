import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Snake {
	
	static class graph {
		int x;
		int y;
		
		graph(int a, int b) {
			x = a;
			y = b;
		}
	}
	
	static class Apple {
		int x;
		int y;
		boolean eat;
		
		Apple(int a, int b, boolean c) {
			x = a;
			y = b;
			eat = c;
		}
	}
	
	static int direction_index = 0;
	static graph direction[] = {new graph(1,0), new graph(0,1), new graph(-1,0), new graph(0,-1)};//동남서북0123
	
	public static void main(String[] args) throws IOException {
		// 일단 단순히 생각
		// 뱀 몸통위치 저장할 자료구조 필요
		int x;
		int y;
		int N;//보드 크기
		int K;//사과 개수
		int L;//방향 전환 개수
		int length = 1;//뱀의 길이
		int time = 0;
		boolean crash = false;
		boolean sw = true;
		
		HashMap<Integer, String> turn = new HashMap<>();//회전 정보 저장
		ArrayList<Apple> apple = new ArrayList<>();//사과 위치 저장
		ArrayList<graph> snake = new ArrayList<>();//뱀 위치정보 저장
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		N = Integer.parseInt(br.readLine());
		K = Integer.parseInt(br.readLine());
		snake.add(new graph(1,1));
		
		for(int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine());
			apple.add(new Apple(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), false));
		}
		
		L = Integer.parseInt(br.readLine());
		for(int i = 0; i < L; i++) {
			st = new StringTokenizer(br.readLine());
			turn.put(Integer.parseInt(st.nextToken()), st.nextToken());
		}
		
		while(true) {
			++time;
			//이동
			sw = false;
			x = snake.get(0).x;
			y = snake.get(0).y;
			snake.add(0, new graph(x + direction[direction_index].x, y + direction[direction_index].y));
			//머리위치에 사과 있는지 파악
			if(K > 0) {
				for(int i = 0; i < apple.size(); i++) {
					if(apple.get(i).x == snake.get(0).x && apple.get(i).y == snake.get(0).y) {
						System.out.println("in");
						if(apple.get(i).eat == false) {
							System.out.println("in");
							apple.get(i).eat = true;
							sw = true;
							++length;
							--K;
						}
						break;
					}
				}
			}
			
			//박았는지 파악
			if(snake.get(0).x <= 0 || snake.get(0).y <= 0 || snake.get(0).x > N || snake.get(0).y > N) {
				break;
			}
			//몸통에 박았는지 파악
			for(int i = 1; i < length; i++) {
				if(snake.get(0).x == snake.get(i).x && snake.get(0).y == snake.get(i).y) {
					crash = true;
					break;
				} 
			}
			
			if(!sw) 
				snake.remove(length);//사과 못 먹은 경우
			
			if(crash) {
				break;
			}
			
			//변환 정보 있는지 파악
			if(turn.containsKey(time)) {
				convert_direction(turn.get(time));
			}
		}
		
		System.out.println(time);
	}

	
	static void convert_direction(String s) {
		if(s.equals("D")) {
			if(direction_index < 3) {
				++direction_index;
			}
			else {
				direction_index = 0;
			}
		}
		else {
			if(direction_index > 0) {
				--direction_index;
			}
			else {
				direction_index = 3;
			}
		}
	}
}
