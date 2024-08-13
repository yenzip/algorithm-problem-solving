import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Solution {
	private static int[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		for(int tc = 1; tc <= 10; tc++) {
			st = new StringTokenizer(br.readLine());
			arr = new int[100][100];
			int x = -1, y = -1;
			
			for(int i = 0; i < 100; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j = 0; j < 100; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
					if(arr[i][j] == 2) {
						x = i;
						y = j;
					}
				}
			}
			
			for(; x > 0; x--) {	// 위로 이동
				if(y > 0 && arr[x][y - 1] == 1) {	// 왼쪽으로 이동
					while(y > 0 && arr[x][y - 1] == 1) {
						y--;
					}
				} else if(y < 99 && arr[x][y + 1] == 1) {	// 오른쪽으로 이동
					while(y < 99 && arr[x][y + 1] == 1) {
						y++;
					}
				}
			}
			
			System.out.println("#" + tc + " " + y);
			
		}
		
		br.close();
	}

}