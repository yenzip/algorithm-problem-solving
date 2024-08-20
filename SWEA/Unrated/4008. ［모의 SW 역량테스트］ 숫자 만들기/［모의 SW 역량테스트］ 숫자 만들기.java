import java.io.*;
import java.util.*;

public class Solution {
	static int N, x;
	static int[] num;
	static int[] op;
	static int max, min;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());

			op = new int[4];
			num = new int[N];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 0; i < 4; i++) {
				op[i] = Integer.parseInt(st.nextToken());
			}


			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				num[i] = Integer.parseInt(st.nextToken());
			}
			
			max = -100_000_000;
			min = 100_000_000;

			dfs(1, num[0]);

			System.out.println("#" + tc + " " + (max - min));
		}

		br.close();
	}

	private static void dfs(int depth, int result) {
		if (depth == N) {
			max = Math.max(max, result);
			min = Math.min(min, result);
			return;
		}

		for (int i = 0; i < 4; i++) {
			if(op[i] == 0) {
				continue;
			}
			
			op[i]--;
			switch(i) {
			case 0:	// '+'
				dfs(depth + 1, result + num[depth]);
				break;
			case 1:	// '-'
				dfs(depth + 1, result - num[depth]);
				break;
			case 2:	// '*'
				dfs(depth + 1, result * num[depth]);
				break;
			case 3:	// '/'
				dfs(depth + 1, result / num[depth]);
				break;
			}
			op[i]++;
		}
	}

}