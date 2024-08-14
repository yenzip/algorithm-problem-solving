import java.io.*;
import java.util.*;

public class Solution {
	private static int N, M;
	private static int[][] arr;
	private static int[][] accumulatedSum;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());

			arr = new int[N][N];
			accumulatedSum = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			accumulatedSum[0][0] = arr[0][0];

			for (int i = 1; i < N; i++) {
				accumulatedSum[0][i] = accumulatedSum[0][i - 1] + arr[0][i];
				accumulatedSum[i][0] = accumulatedSum[i - 1][0] + arr[i][0];
			}

			for (int i = 1; i < N; i++) {
				for (int j = 1; j < N; j++) {
					accumulatedSum[i][j] = accumulatedSum[i][j - 1] + accumulatedSum[i - 1][j] + arr[i][j]
							- accumulatedSum[i - 1][j - 1];
				}
			}

			int answer = accumulatedSum[M - 1][M - 1];

			for (int i = M - 1; i < N; i++) {
				for (int j = M - 1; j < N; j++) {
					if (i == M - 1 && j == M - 1) {
						continue;
					}
					int sum = accumulatedSum[i][j];
					if (i - M >= 0) {
						sum -= accumulatedSum[i - M][j];
					}
					if (j - M >= 0) {
						sum -= accumulatedSum[i][j - M];
					}
					if (i - M >= 0 && j - M >= 0) {
						sum += accumulatedSum[i - M][j - M];
					}
					answer = Math.max(answer, sum);
				}
			}

			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();

	}

}