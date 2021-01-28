import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Ipv6 {

	public static void main(String[] args) throws IOException {
		// 문자열
		// 일단 있는그대로 단순히 구현
		int index;
		String s;
		String ans = "";
		String[] split;
		ArrayList<String> list = new ArrayList<>();
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		
		split = s.split(":");
		if(s.equals("::")) { //하드코딩 부분
			split = new String[2];
			split[0] = "";
			split[1] = "";
		}
		
		for(String i : split) {
			if(i.length() == 4) {
				list.add(i);
			}
			else {
				if(i.length() == 0) {
					list.add(i);
				}
				else {
					while(i.length() != 4) {
						i = "0" + i;
					}
					list.add(i);
				}
			}
		}
		
		index = list.indexOf("");
		
		if(index == -1 && list.size() < 8) { //하드코딩 부분
			//1::같은 경우에서 스플릿이 제대로 되지 않는 경우 방지
			list.add("");
			list.add("");
			index = list.indexOf("");
		}
		
		if(index == 0) {//::1 이런형태일때
			list.remove(0);
			list.remove(0);
			while(list.size() < 8) {
				list.add(0, "0000");
			}
		}
		else {//1:: 또는 6::6이런형태 또는 아예 ::이게 없을 때
			if(index == list.size() - 2) {
				if(list.get(list.size() - 2) == "" && list.get(list.size() - 1) == "") {
					list.remove(list.size() - 2);
					list.remove(list.size() - 1);
					while(list.size() < 8) {
						list.add("0000");
					}
				}
				else {
					list.remove(index);
					while(list.size() < 8) {
						list.add(index, "0000");
					}
				}
			}
			else {
				if(index != -1) {
					list.remove(index);
					while(list.size() < 8) {
						list.add(index, "0000");
					}
				}
			}
		}
		
		ans = list.get(0);
		for(int i = 1; i < list.size(); i++) {
			ans = ans + ":" + list.get(i);
		}
		System.out.println(ans);
	}

}
