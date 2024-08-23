import java.io.*;
import java.util.*;

public class Solution {
    static int[][] map;
    static int M, A;
    static int[] a, b;
    static int ax, ay, bx, by;
    static Battery[] batteries;
    static int[] dx = {0, -1, 0, 1, 0};
    static int[] dy = {0, 0, 1, 0, -1};
    static int answer;
    
    static class Battery {
        int x, y, c, p;
        Battery(int x, int y, int c, int p) {
            this.x = x;
            this.y = y;
            this.c = c;
            this.p = p;
        }
    }
    
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        int T = Integer.parseInt(br.readLine());
        
        for(int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
            
            map = new int[10][10];
            a = new int[M + 1];
            b = new int[M + 1];
            
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < M; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < M; i++) {
                b[i] = Integer.parseInt(st.nextToken());
            }
            
            batteries = new Battery[A];
            
            for(int i = 0; i < A; i++) {
                st = new StringTokenizer(br.readLine());
                int y = Integer.parseInt(st.nextToken());
                int x = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());
                int p = Integer.parseInt(st.nextToken());
                batteries[i] = new Battery(x - 1, y - 1, c, p);
            }
            
            answer = 0;
            ax = 0; ay = 0;
            bx = 9; by = 9;
            
            for(int i = 0; i <= M; i++) {
                List<Integer> batteryA = check(ax, ay);   // M * A = 800
                List<Integer> batteryB = check(bx, by);
                
                int maxA = batteryA.stream().mapToInt(j -> batteries[j].p).max().orElse(0);
                int maxB = batteryB.stream().mapToInt(j -> batteries[j].p).max().orElse(0);
                
                // 중복 배터리의 최대 충전량을 계산합니다
                int maxOverlap = batteryA.stream()
                                         .flatMapToInt(a -> batteryB.stream().mapToInt(b -> (a == b) ? batteries[a].p : batteries[a].p + batteries[b].p))
                                         .max()
                                         .orElse(0);
                
                int sum = Math.max(maxA + maxB - maxOverlap, maxOverlap);
                answer += sum;
                
                ax += dx[a[i]]; 
                ay += dy[a[i]];
                bx += dx[b[i]];
                by += dy[b[i]];    
            } 
            
            System.out.println("#" + tc + " " + answer);
            
        }
        
        br.close();
    }
    
    static List<Integer> check(int x, int y) {
        List<Integer> batteryList = new ArrayList<>();
        
        for(int i = 0; i < A; i++) {
            int bx = batteries[i].x;
            int by = batteries[i].y;
            
            if(distance(x, y, bx, by) <= batteries[i].c) {
                batteryList.add(i);
            }
        }
        
        return batteryList;
    }
    
    static int distance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }
}