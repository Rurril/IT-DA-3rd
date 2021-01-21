import java.util.*;

public class 2504_힝.. {
	
	//static char gwalhou[];
	static String gwalhou[];
	static Stack<String> ss = new Stack<String>();

	public static void main(String[] args) {
		
		/**
		 * https://mygumi.tistory.com/175
		 * 참고했습니다
		 * 
		 * 맞았지만 시간이 너무 오래걸림 ^_ㅜ....
		 * 힝..
		 */
		
		Scanner input = new Scanner(System.in);
		
		String S = input.next();
		gwalhou = S.split("");
		
		int check = 0;
		
		for(int i = 0; i < S.length(); i++) {
			
			if(check == -1) {
				System.out.println("0");
				return;
			}
			
			if(gwalhou[i].equals("(") || gwalhou[i].equals("["))
				ss.push(gwalhou[i]);
			
			else {
				
				/**
				 * 이거 처리를 안해주면 런타임 에러가 뜬다..
				 */
				if(ss.isEmpty()) {
					System.out.println("0");
					return;
				}
				
				if(gwalhou[i].equals(")")) {
					
					if(ss.peek().equals("(")) {
						ss.pop();
						ss.push("2");
					}
					else
						check = checking("[", "(", 2);
				}
				
				else if(gwalhou[i].equals("]")) {
					
					
					if(ss.peek().equals("[")) {
						ss.pop();
						ss.push("3");
					}
					else
						check = checking("(", "[", 3);
				}
			}
		}
		
		int answer = 0;
		
		for(int j = 0; j < ss.size(); j++) {
			
			if(ss.get(j).equals("(") || ss.get(j).equals(")") ||
					ss.get(j).equals("[") || ss.get(j).equals("]")) {
				
				System.out.println("0");
				return;
			}
			
			answer = answer + Integer.parseInt(ss.get(j));
		}
		
		System.out.println(answer);
	}
	
	public static int checking(String wrong, String right, int value) {
		
		int check_sum = 0;
		
		while(!ss.isEmpty()) { 
		//while(ss.isEmpty()) { 진짜 죽고싶다......... !안해서...........
			
			String top = ss.peek();
			
			if(top.equals(wrong))
				return -1;
			
			else if(top.equals(right)) {
				
				ss.pop();
				check_sum = check_sum * value;
				ss.push(Integer.toString(check_sum));
				break;
			}
			
			else { // 숫자라면
				check_sum = check_sum + Integer.parseInt(ss.pop());
			}
		}
		
		return check_sum;
		
	}

}
