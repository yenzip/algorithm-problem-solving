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

		for (int tc = 1; tc <= T; tc++) {
			tickets = new int[4];
			month = new int[12];

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 4; i++) {
				tickets[i] = Integer.parseInt(st.nextToken());
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < 12; i++) {
				month[i] = Integer.parseInt(st.nextToken());
			}

			answer = tickets[3];	// 최소 비용을 1년 이용권으로 초기화
			dfs(0, 0);

			System.out.println("#" + tc + " " + answer);
		}

		br.close();
	}

	private static void dfs(int depth, int cost) {
		// 모든 달을 처리한 경우
		if (depth >= 12) {
			answer = Math.min(answer, cost);
			return;
		}
		
		// 가지치기: 현재 비용이 이미 최소 비용보다 크면 더 이상 탐색하지 않습니다.
		if(cost >= answer) {
			return;
		}

		if (month[depth] == 0) {
			dfs(depth + 1, cost);
			return;
		}

		// 1. 1일 이용권 사용
		dfs(depth + 1, cost + month[depth] * tickets[0]);

		// 2. 1개월 이용권 사용
		dfs(depth + 1, cost + tickets[1]);

		// 3. 3개월 이용권 사용
		dfs(depth + 3, cost + tickets[2]);
	}
}