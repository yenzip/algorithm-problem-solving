import java.io.*;
import java.util.*;

public class Solution {
	static int N;
	static String dir;
	static int[][] arr;
	static Queue<Integer> q;
	static Deque<Integer> dq;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int T = Integer.parseInt(br.readLine());

		for (int tc = 1; tc <= T; tc++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			dir = st.nextToken();

			arr = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			switch (dir) {
			case "up":
				up();
				break;
			case "down":
				down();
				break;
			case "left":
				left();
				break;
			case "right":
				right();
			}

			System.out.println("#" + tc);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					System.out.print(arr[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	private static void play2048() {
		dq = new ArrayDeque<>();
		while (!q.isEmpty()) {
			int x = q.poll();
			if (q.size() > 0 && q.peek() == x) {
				x *= 2;
				q.poll();
			}
			dq.offer(x);
		}
		while (dq.size() < N) {
			dq.offer(0);
		}
	}

	private static void up() {
		for (int j = 0; j < N; j++) {
			q = new LinkedList<>();
			for (int i = 0; i < N; i++) {
				if (arr[i][j] == 0) {
					continue;
				}
				q.offer(arr[i][j]);

			}
			play2048();
			for (int i = 0; i < N; i++) {
				arr[i][j] = dq.poll();
			}
		}
	}

	private static void down() {
		for (int j = 0; j < N; j++) {
			q = new LinkedList<>();
			for (int i = N - 1; i >= 0; i--) {
				if (arr[i][j] == 0) {
					continue;
				}
				q.offer(arr[i][j]);
			}
			play2048();
			for (int i = N - 1; i >= 0; i--) {
				arr[i][j] = dq.poll();
			}
		}
	}

	private static void left() {
		for (int i = 0; i < N; i++) {
			q = new LinkedList<>();
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				q.offer(arr[i][j]);
			}
			play2048();
			for (int j = 0; j < N; j++) {
				arr[i][j] = dq.poll();
			}
		}
	}

	private static void right() {
		for (int i = 0; i < N; i++) {
			q = new LinkedList<>();
			for (int j = N - 1; j >= 0; j--) {
				if (arr[i][j] == 0) {
					continue;
				}
				q.offer(arr[i][j]);
			}
			play2048();
			for (int j = N - 1; j >= 0; j--) {
				arr[i][j] = dq.poll();
			}
		}
	}
}