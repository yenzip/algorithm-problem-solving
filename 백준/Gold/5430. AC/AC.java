import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		while(T-- > 0) {
			String p = br.readLine();
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine(), "[],");
			
			Deque<Integer> dq = new ArrayDeque<>();
			
			for(int i = 0; i < n; i++) {
				dq.offer(Integer.parseInt(st.nextToken()));
			}
			
			boolean isFront = true;	// 배열의 순서가 앞부터 인지 확인
			boolean isError = false;
			
			for(char c : p.toCharArray()) {
				if(c == 'R') {
					isFront = !isFront;
				} else if(c == 'D') {
					if(dq.isEmpty()) {
						isError = true;
						break;
					}
					if(isFront) {
						dq.pollFirst();
					} else {
						dq.pollLast();
					}
				}
			}
			
			if(isError) {
				sb.append("error\n");
			} else {
				sb.append("[");
				while(!dq.isEmpty()) {
					sb.append(isFront ? dq.pollFirst() : dq.pollLast());
					
					if(!dq.isEmpty()) {
						sb.append(",");
					}
				}
				sb.append("]\n");
			}
		}
		
		System.out.println(sb);
		
		br.close();
	}
}