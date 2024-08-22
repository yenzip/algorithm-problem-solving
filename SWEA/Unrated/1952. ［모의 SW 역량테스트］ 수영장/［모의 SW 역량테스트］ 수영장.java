import java.io.*;
import java.util.*;

public class Solution {
	static int[] tickets;
	static int[] month;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			tickets = new int[4];
			month = new int[12];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 4; i++) {
				tickets[i] = Integer.parseInt(st.nextToken());
			}
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 12; i++) {
				month[i] = Integer.parseInt(st.nextToken());
			}
			
			answer = 12_000;
			dfs(0, 0);
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}
	
	private static void dfs(int depth, int cost) {
		if(depth >= 12) {
			answer = Math.min(answer, cost);
			return;
		}
		
		if(month[depth] == 0) {
			dfs(depth + 1, cost);
		} else {
			// 1. 1일 이용권 사용
			dfs(depth + 1, cost + month[depth] * tickets[0]);
			
			// 2. 1개월 이용권 사용
			dfs(depth + 1, cost + tickets[1]);
			
			// 3. 3개월 이용권 사용
			dfs(depth + 3, cost + tickets[2]);
			
			// 4. 1년 이용권 사용
			dfs(depth + 12, cost + tickets[3]);
		}
	}
}