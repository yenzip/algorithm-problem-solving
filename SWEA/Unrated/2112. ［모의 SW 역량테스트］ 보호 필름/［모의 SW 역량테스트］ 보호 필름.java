import java.io.*;
import java.util.*;

public class Solution {
	static int D, W, K;
	static int[][] arr;
	static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
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

			answer = D;
			dfs(0, 0);
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}
	
	private static void dfs(int depth, int count) {	// count: 약품을 처리한 횟수
		if (count >= answer) {  // 조기 종료 조건: 현재 처리한 약품의 수가 이미 최소값 이상일 경우
            return;
        }
		
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
			for(int i = 1; i < D; i++) {
				if(arr[i - 1][j] == arr[i][j]) {
					count++;
				} else {
					count = 1;
				}				
				if(count >= K) {
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