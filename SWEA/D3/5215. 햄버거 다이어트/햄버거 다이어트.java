import java.io.*;
import java.util.*;

public class Solution {
	private static int N, L;
	private static int[] T, K;
	private static int answer;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int TC = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= TC; tc++) {
			st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			L = Integer.parseInt(st.nextToken());
			
			T = new int[N];
			K = new int[N];
			answer = 0;	// 높은 햄버거의 점수
			
			for(int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				T[i] = Integer.parseInt(st.nextToken());
				K[i] = Integer.parseInt(st.nextToken());
			}
			
			combination(0, 0, 0);
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}
	
	private static void combination(int index, int score, int calorie) {
		if(calorie > L) {
			return;
		}
		
		if(index == N) {
			answer = Math.max(answer, score);
			return;
		}

		combination(index + 1, score + T[index], calorie + K[index]);
		combination(index + 1, score, calorie);
	}

}