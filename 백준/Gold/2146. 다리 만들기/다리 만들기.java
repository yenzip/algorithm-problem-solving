import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] A;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int answer = 10000;
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        A = new int[N][N];
        visited = new boolean[N][N];
        
        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                A[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int island = 1; // 1. 대륙 나누고 번호 매기기
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][j] == 1 && !visited[i][j]) {
                    dfs(i, j, island++);
                }
            }
        }
        
        for(int i = 1; i < island; i++) {   // 2. 섬 별로 최단 거리 구하기
            bfs(i);
        }
        
        System.out.println(answer);
        
        br.close();
    }
    
    public static boolean isOut(int x, int y) {
        return (x < 0 || x >= N || y < 0 || y >= N);
    }
    
    public static void dfs(int x, int y, int island) {
        A[x][y] = island;
        visited[x][y] = true;
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isOut(nx, ny) && A[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny, island);
            }
        }
    }
    
    public static void bfs(int island) {
        Queue<int[]> q = new LinkedList<>();
        visited = new boolean[N][N];
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(A[i][j] == island) {
                    q.offer(new int[]{i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0];
            int y = p[1];
            int dist = p[2];
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isOut(nx, ny) || A[nx][ny] == island || visited[nx][ny]) {
                    continue;
                }
                
                if(A[nx][ny] != 0 && A[nx][ny] != island) {
                    answer = Math.min(answer, dist);
                    return;
                }
                
                q.offer(new int[]{nx, ny, dist + 1});
                visited[nx][ny] = true;
            }
        }
    }
}