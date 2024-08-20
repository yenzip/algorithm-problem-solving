import java.io.*;
import java.util.*;

public class Solution {
	static int N, B;
	static int[] H;
	static boolean[] visited;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			
			H = new int[N];
			visited = new boolean[N];
			answer = 0;
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) {
				H[i] = Integer.parseInt(st.nextToken());
				answer += H[i];
			}
			
			answer -= B;
			dfs(0, 0);
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}
	
	private static void dfs(int depth, int sum) {
		if(depth == N) {
			if(sum >= B) {
				answer = Math.min(answer, sum - B);
			}
			return;
		}
		
		dfs(depth + 1, sum + H[depth]);
		dfs(depth + 1, sum);
	}

}