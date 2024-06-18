import java.util.*;

class Solution {
    int n, m;
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, -1, 1};
    
    private boolean isOut(int x, int y) {
        return (x < 0 || x >= n || y < 0 || y >= m);
    }
    
    private int bfs(int[][] maps) {
        Queue<int[]> q = new LinkedList<>();
        
        q.offer(new int[]{0, 0});
        
        while(!q.isEmpty()) {
            int[] p = q.poll();
            int x = p[0];
            int y = p[1];
            
            if(x == n - 1 && y == m - 1) {
                return maps[x][y];
            }
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(isOut(nx, ny) || maps[nx][ny] != 1) {
                    continue;
                }
                
                q.offer(new int[]{nx, ny});
                maps[nx][ny] = maps[x][y] + 1;
            }
        }
        
        return -1;
    }
    
    
    public int solution(int[][] maps) {
        n = maps.length;
        m = maps[0].length;  
        
        return bfs(maps);
    }
}