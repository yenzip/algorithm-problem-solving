import java.io.*;
import java.util.*;

public class Solution {
	private static int N, M;
	private static int[][] arr;
	private static int[][] prefixSum;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());

			arr = new int[N][N];
			prefixSum = new int[N + 1][N + 1];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					prefixSum[i][j] = prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1] + arr[i - 1][j - 1];
				}
			}

			int answer = Integer.MIN_VALUE;

			for (int i = M; i <= N; i++) {
				for (int j = M; j <= N; j++) {
					answer = Math.max(answer, prefixSum[i][j] - prefixSum[i - M][j] - prefixSum[i][j - M] + prefixSum[i - M][j - M]);
				}
			}

			System.out.println("#" + tc + " " + answer);
		}

		br.close();

	}

}