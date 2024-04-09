import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] A;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int answer = 0, sharkSize = 2;
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        N = Integer.parseInt(br.readLine());
      
        A = new int[N][N];
        visited = new boolean[N][N];
        
        int sx = 0, sy = 0;
      
        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
                
                if(A[i][j] == 9) {
                    sx = i;
                    sy = j;
                    A[i][j] = 0;
                }
            }
        }
        
        simulation(sx, sy);
        
        System.out.println(answer);
        
        br.close();
    }
    
    static boolean isOut(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y >= N);
    }

    static void simulation(int sx, int sy) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if (o1[0] == o2[0]) {
                if (o1[1] == o2[1]) {
                    return Integer.compare(o1[2], o2[2]);
                }
                return Integer.compare(o1[1], o2[1]);
            }
            return Integer.compare(o1[0], o2[0]);
        });
        int eat = 0;

        pq.add(new int[]{0, sx, sy});
        visited[sx][sy] = true;

        while (!pq.isEmpty()) {
            int[] p = pq.poll();
            int dist = p[0];
            int x = p[1];
            int y = p[2];

            if (A[x][y] != 0 && A[x][y] < sharkSize) {
                answer = dist;
                eat++;

                if (eat == sharkSize) {
                    sharkSize++;
                    eat = 0;
                }

                pq.clear();
                visited = new boolean[N][N];

                pq.add(new int[]{0, x, y});
                visited[x][y] = true;
                A[x][y] = 0;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (isOut(nx, ny) || visited[nx][ny] || A[nx][ny] > sharkSize) {
                    continue;
                }

                pq.add(new int[]{dist + 1, nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}