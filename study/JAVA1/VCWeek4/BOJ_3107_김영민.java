import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class BOJ_3107_김영민 {

	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String contraction = br.readLine();
		String[] doubleColon = contraction.split("::");
		int ipv6Length = contraction.split(":").length;
		StringBuilder sb = new StringBuilder();

		if (contraction.contains("::")) {
			System.out.println("double:"+doubleColon.length);
			System.out.println("ipv6:"+ipv6Length);
			if (doubleColon.length == 0) {
				System.out.println("0000:0000:0000:0000:0000:0000:0000:0000");
				return;
			} else if (doubleColon.length == 1) {
				contraction = contraction.replaceAll("::", ":0000:0000:0000:0000:0000:0000:0000");	
			} else {
				System.out.println(8-ipv6Length);
				String temp = "";
				for(int i=0; i<=8-ipv6Length; i++) {
					if(i!=8-ipv6Length) {
						temp += ":0000";
					} else {
						temp += ":0000:";
					}
				}
				contraction = contraction.replaceAll("::", temp);
			}
			System.out.println(contraction);
		}
		
		String[] ipv6 = contraction.split(":");
		
		for (int i = 0; i < ipv6.length; i++) {
			if (ipv6[i].length() != 4) {
				int tempLength = 4 - ipv6[i].length();
				for (int j = 0; j < tempLength; j++) {
					sb.append("0");
				}
			}
			if (i < ipv6.length - 1) {
				sb.append(ipv6[i] + ":");
			} else {
				sb.append(ipv6[i]);
			}
		}

		System.out.print(sb.toString());
	}
}
