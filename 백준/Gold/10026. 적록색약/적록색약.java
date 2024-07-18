import java.io.*;
import java.util.*;

public class Main {
	static int N;
	static char[][] map;
	static char[][] cMap;	// 적록색약
	static boolean[][] visited;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		map = new char[N][N];
		cMap = new char[N][N];
		visited = new boolean[N][N];
		
		for(int i = 0; i < N; i++) {
			String line = br.readLine();
			for(int j = 0; j < N; j++) {
				map[i][j] = line.charAt(j);
				cMap[i][j] = (map[i][j] == 'B' ? 'B' : 'C');	// 적록색약은 R과 G를 C로 표현
			}
		}
		
		int answer1 = 0;	// 적록색약이 아닌 사람이 봤을 때 구역의 수
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(!visited[i][j]) {
					bfs(map, i, j, map[i][j]);
					answer1++;
				}
			}
		}
		
		int answer2 = 0;	// 적록색약인 사람이 봤을 때 구역의 수
		visited = new boolean[N][N];
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(!visited[i][j]) {
					bfs(cMap, i, j, cMap[i][j]);
					answer2++;
				}
			}
		}
		
		System.out.println(answer1 + " " + answer2);
		
		br.close();
	}
	
	private static void bfs(char[][] arr, int x, int y, char c) {
		Queue<int[]> q = new LinkedList<>();
		
		visited[x][y] = true;
		q.offer(new int[] {x, y});
		
		while(!q.isEmpty()) {
			int[] p = q.poll();
			x = p[0];
			y = p[1];
			
			for(int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(isOutOfBounds(nx, ny) || visited[nx][ny] || arr[nx][ny] != c) {
					continue;
				}
				
				visited[nx][ny] = true;
				q.offer(new int[] {nx, ny});
			}
		}
	}
	
	private static boolean isOutOfBounds(int x, int y) {
		return (x < 0 || x >= N || y < 0 || y >= N);
	}

}
