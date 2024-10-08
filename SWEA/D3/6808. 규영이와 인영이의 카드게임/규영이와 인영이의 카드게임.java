import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	private static boolean[] card;	// 규영이 카드인지 확인
	private static int[] kyuyoung;
	private static int[] inyoung;
	private static int win, loose;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			card = new boolean[19];
			kyuyoung = new int[9];
			inyoung = new int[9];
			win = 0;
			loose = 0;
			
			for(int i = 0; i < 9; i++) {
				int number = Integer.parseInt(st.nextToken());
				kyuyoung[i] = number;
				card[number] = true;
			}
			
			int index = 0;
			for(int i = 1; i <= 18; i++) {
				if(!card[i]) {
					inyoung[index++] = i;
				}
			}
			
			swapPermutation(0);
			
			System.out.println("#" + tc + " " + win + " " + loose);
		}
	}
	
	private static void swapPermutation(int depth) {
		if(depth == 9) {
			if(isKyuyoungWin()) {
				win++;
			} else {
				loose++;
			}
			return;
		}
		
		for(int i = depth; i < 9; i++) {
			swap(depth, i);
			swapPermutation(depth + 1);
			swap(depth, i);
		}
	}
	
	private static boolean isKyuyoungWin() {
		int kyu = 0;
		int in = 0;
		for(int i = 0; i < 9; i++) {
			if(kyuyoung[i] > inyoung[i]) {
				kyu += kyuyoung[i] + inyoung[i];
			} else {
				in += kyuyoung[i] + inyoung[i];
			}
		}
		return kyu > in;
	}
	
	private static void swap(int i, int j) {
		int tmp = inyoung[i];
		inyoung[i] = inyoung[j];
		inyoung[j] = tmp;
	}

}