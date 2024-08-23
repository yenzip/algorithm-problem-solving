import java.io.*;
import java.util.*;

public class Solution {
	static int N;
	static Point[] customers;
	static int sx, sy, ex, ey;
	static boolean[] visited;
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	static int answer;
	static int dist;
	
	static class Point {
		int x, y;
		Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine());
			sx = Integer.parseInt(st.nextToken());
			sy = Integer.parseInt(st.nextToken());
			ex = Integer.parseInt(st.nextToken());
			ey = Integer.parseInt(st.nextToken());
			
			customers = new Point[N];				
			visited = new boolean[N];
			
			for(int i = 0; i < N; i++) {
				customers[i] = new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
			}
			
			answer = 10000;
			dist = 0;
			
			dfs(sx, sy, 0);
			
			System.out.println("#" + tc + " " + answer);
		}
		
		br.close();
	}
	
	private static void dfs(int x, int y, int depth) {
		if(depth == N) {
			answer = Math.min(answer, dist + distance(x, y, ex, ey));
			return;
		}
		
		if(dist >= answer) {
			return;
		}

		for(int i = 0; i < N; i++) {
			int nx = customers[i].x;
			int ny = customers[i].y;
			
			if(!visited[i]) {
				visited[i] = true;
				dist += distance(x, y, nx, ny);
				dfs(nx, ny, depth + 1);
				visited[i] = false;
				dist -= distance(x, y, nx, ny);
			}
		}
	}
	
	private static int distance(int x1, int y1, int x2, int y2) {
		return Math.abs(x1 - x2) + Math.abs(y1 - y2);
	}
}