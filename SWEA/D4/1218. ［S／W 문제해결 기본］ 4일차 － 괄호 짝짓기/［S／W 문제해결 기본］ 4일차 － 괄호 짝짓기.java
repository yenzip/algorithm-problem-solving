import java.io.*;
import java.util.*;

public class Solution {
	private static Map<Character, Character> map = new HashMap<Character, Character>() {{
		put(')', '(');
		put(']', '[');
		put('}', '{');
		put('>', '<');
	}};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int tc = 1; tc <= 10; tc++) {
			int N = Integer.parseInt(br.readLine());
			String s = br.readLine();
			
			Deque<Character> stk = new ArrayDeque<>();
			int answer = 1;	// 유효함
			
			for(char c : s.toCharArray()) {
				if(c == '(' || c == '[' || c == '{' || c == '<') {	// 여는 괄호
					stk.offer(c);
				} else {
					if(stk.peekLast() != map.get(c)) {
						answer = 0;
						break;
					}
					stk.pollLast();
				}
			}
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}

}