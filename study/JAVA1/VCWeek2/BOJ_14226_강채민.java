import java.util.*;

public class 14226_이모티콘 {

	public static void main(String[] args) {
		
		/**
		 * https://jdselectron.tistory.com/57
		 * 참고했습니다.
		 * 
		 * 점점 코딩 실력이 바보가 되어가는 느낌..? 
		 */
		
		Scanner input = new Scanner(System.in);
		
		int S = input.nextInt();
		
		/**
		 * class를 하나 만들어야겠지..?
		 * 
		 * 그리고 return은 time을 해주면 되니까...
		 */
		
		int check[][] = new int[1001][1001];
		
		Queue<Emoticon> Q = new LinkedList<Emoticon>();
		
		Q.add(new Emoticon(1, 0, 0));
		check[1][0] = 1;
		
		while(!Q.isEmpty()) {
			
			Emoticon E = Q.poll();
			
			/**
			 * 변수를 두는게 더 편하겠다.. 읽기 조금 복잡한듯..
			 */
			
			int display = E.display;
			int clipboard = E.clipboard;
			int time = E.time;
			
			if(display == S) {
				System.out.println(time);
				return;
			}
			
			//1. 클립보드에 복사하는 경우 
			// 화면에 1개 이상이여야한다.
			if(display >= 1 && display <= 1000) {
				
				if(check[display][display] != 1) {
					/**
					 * clipboard = display; // 클립보드에 복사는 덮어씌우기 이기 때문
						time++;
						이거는 check 밖에다가 해줘야한다..
						
						이걸 이렇게 해주면 안되는구나.. 밑에도 덮어쓰기가 되어서..
					 */
					Q.add(new Emoticon(display, display, time+1));
					check[display][display] = 1;
				}
				
				//2. 붙여넣기를 하는 경우
				// clipboard가 비어있지 않아야 한다.
				//if(clipboard >= 0 && clipboard <= 1000) {
				if(clipboard > 0 && display + clipboard <= 1000) {
					
					/**
					 * display = display + clipboard;
					 * time++;
					 */
					
					if(check[display + clipboard][clipboard] != 1) {
						
						Q.add(new Emoticon(display + clipboard, clipboard, time+1));
						check[display + clipboard][clipboard] = 1;
					}
				}
				
				//3. 화면에 있는거 지우는 경우
				if(check[display-1][clipboard] != 1) {
					/**
					display--;
					time++;
					*/
					Q.add(new Emoticon(display-1, clipboard, time+1));
					check[display-1][clipboard] = 1;
				}
			}
		}

	}
	
	public static class Emoticon {
		
		int display;
		int clipboard;
		int time;
		
		public Emoticon(int display, int clipboard, int time) {
			this.display = display;
			this.clipboard = clipboard;
			this.time = time;
		}
	}

}
