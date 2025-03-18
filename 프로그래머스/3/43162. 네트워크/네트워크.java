import java.io.*;
import java.util.*;

class Solution {
    static int N;
    static boolean[] visited;
    
    public int solution(int n, int[][] computers) {
        int answer = 0; // 네트워크의 개수
        
        N = computers.length;
        visited = new boolean[N + 1];
        
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(i, computers);
                answer++;
            }
        }
        
        return answer;
    }
    
    private void dfs(int now, int[][] computers) {
        visited[now] = true;
        
        for(int next = 0; next < N; next++) {
            if(computers[now][next] == 1 && !visited[next]) {
                dfs(next, computers);
            }
        }
    }
    
}