import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			int[][] arr = new int[N][N];
			
			int num = 1;
			int i = 0;
			int j = 0;
			
			while(num <= N * N) {
				while(j < N && arr[i][j] == 0) {
					arr[i][j++] = num++;
				}
				i++;
				j--;
				
				while(i < N && arr[i][j] == 0) {
					arr[i++][j] = num++;
				}
				i--;
				j--;
				
				while(j >= 0 && arr[i][j] == 0) {
					arr[i][j--] = num++;
				}
				i--;
				j++;
			
				while(i >= 0 && arr[i][j] == 0) {
					arr[i--][j] = num++;
				}
				i++;
				j++;
			}
			
			System.out.println("#" + tc);
			
			for(i = 0; i < N; i++) {
				for(j = 0; j < N; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
		}
		
		br.close();
	}

}
