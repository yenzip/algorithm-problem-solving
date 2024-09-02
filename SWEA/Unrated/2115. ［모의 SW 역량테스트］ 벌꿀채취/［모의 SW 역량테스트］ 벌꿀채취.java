import java.io.*;
import java.util.*;

public class Solution {
    static int N, M, C;
    static int[][] map;
    static boolean[][] visited;
    static int result, answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int T = Integer.parseInt(br.readLine());

        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            map = new int[N][N];
            visited = new boolean[N][N];

            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                }
            }

            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[2] - a[2]);
            for (int i = 0; i < N; i++) {
                for (int j = 0; j <= N - M; j++) {
                    result = 0;
                    dfs(i, j, 0, 0, 0);
                    pq.offer(new int[]{i, j, result});
                }
            }

            int worker = 0;
            answer = 0;
            while (!pq.isEmpty() && worker < 2) {
                int[] info = pq.poll();
                int x = info[0];
                int y = info[1];
                int cost = info[2];
                boolean isOkay = true;

                // 각 일꾼이 선택한 범위를 방문 표시
                for (int j = 0; j < M; j++) {
                    if (visited[x][y + j]) {
                        isOkay = false;
                        break;
                    }
                }
                if (!isOkay) {
                    continue;
                }

                for (int j = 0; j < M; j++) {
                    visited[x][y + j] = true;
                }

                answer += cost;
                worker++;
            }
            
            System.out.println("#" + tc + " " + answer);
        }
    }

    static void dfs(int x, int y, int depth, int sum, int cost) {
        if (sum > C) {
            return;
        }

        if (depth == M) {
            result = Math.max(result, cost);
            return;
        }

        // 선택 O
        dfs(x, y + 1, depth + 1, sum + map[x][y], cost + map[x][y] * map[x][y]);
        // 선택 X
        dfs(x, y + 1, depth + 1, sum, cost);
    }
}