import java.io.*;
import java.util.*;

public class Solution {
	static int D, W, K;
	static int[][] arr;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			sb.append('#').append(tc).append(' ');
			
			st = new StringTokenizer(br.readLine());
			D = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			arr = new int[D][W];
			
			for(int i = 0; i < D; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < W; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			if(K == 1) {
				sb.append(0).append('\n');
				continue;
			}
			
			answer = D;
			dfs(0, 0);
			
			sb.append(answer).append('\n');
		}
		
		System.out.println(sb);
		
		br.close();
	}
	
	private static void dfs(int depth, int count) {	// count: 약품을 처리한 횟수
		if(depth == D) {
			if(checkIfPassed()) {
				answer = Math.min(answer, count);
			}
			return;
		}
		
		// 1. 약품을 처리하지 않음
		dfs(depth + 1, count);	
		
		// 2. A 약품 처리
		int[] originalRow = arr[depth].clone();  // 원래의 배열을 복사하여 저장
		Arrays.fill(arr[depth], 0);
		dfs(depth + 1, count + 1);
		
		// 3. B 약품 처리
		Arrays.fill(arr[depth], 1);
		dfs(depth + 1, count + 1);
		
		arr[depth] = originalRow;	// 원래 상태로 복원
	}
	
	private static boolean checkIfPassed() {
		for(int j = 0; j < W; j++) {
			boolean valid = false;
			int count = 1;
			for(int i = 0; i < D - 1; i++) {
				if(arr[i][j] != arr[i + 1][j]) {
					count = 1;
					continue;
				}
				count++;
				if(count == K) {
					valid = true;
					break;
				}
			}
			if(!valid) {
				return false;
			}
		}
		return true;
	}

}