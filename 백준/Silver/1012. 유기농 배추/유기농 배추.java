import java.io.*;
import java.util.*;

public class Main {
	static int N, M, K;
	static int[][] land;
	static boolean[][] visited;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int T = Integer.parseInt(st.nextToken());
		
		while(T-- > 0) {
			st = new StringTokenizer(br.readLine());
			
			M = Integer.parseInt(st.nextToken());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			land = new int[N][M];
			visited = new boolean[N][M];
			
			for(int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine());
				int Y = Integer.parseInt(st.nextToken());
				int X = Integer.parseInt(st.nextToken());
				land[X][Y] = 1;
			}
			
			int answer = 0;
			
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(!visited[i][j] && land[i][j] == 1) {
						dfs(i, j);
						answer++;
					}
				}
			}
			
			System.out.println(answer);
		}
		
		br.close();
	}
	
	private static void dfs(int x, int y) {
		visited[x][y] = true;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(isOutOfBounds(nx, ny) || visited[nx][ny] || land[nx][ny] == 0) {
				continue;
			}
			
			dfs(nx, ny);
		}
	}
	
	private static boolean isOutOfBounds(int x, int y) {
		return (x < 0 || x >= N || y < 0 || y >= M);
	}

}
