import java.io.*;
import java.util.*;

public class Main {

    static class Node{
        int x;
        int y;
        int virus;
        int time;

        public Node(int x, int y, int virus, int time) {
            this.x = x;
            this.y = y;
            this.virus = virus;
            this.time = time;
        }
    }

    static final int[] dx = {0, 0, -1, 1};
    static final int[] dy = {1, -1, 0, 0};
    static int n, k, s, x, y;
    static int[][] a;
    static Queue<Node> q = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        a = new int[n + 1][n + 1];
        List<Node> list = new ArrayList<>();

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                a[i][j] = Integer.parseInt(st.nextToken());
                
                if (a[i][j] != 0) {
                    list.add(new Node(i, j, a[i][j], 0));
                }
            }
        }

        st = new StringTokenizer(br.readLine());
        s = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        y = Integer.parseInt(st.nextToken());

        Collections.sort(list, (o1, o2) -> o1.virus - o2.virus);

        for (Node node : list) {
            q.offer(node);
        }

        bfs();

        System.out.println(a[x][y]);
    }

    static void bfs() {
        while (!q.isEmpty()) {
            Node now = q.poll();

            if (now.time == s) {
                return;
            }

            for (int i = 0; i < 4; i++) {
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];

                if(isOut(nx, ny) || a[nx][ny] != 0) {
                    continue;
                }
                
                q.offer(new Node(nx, ny, now.virus, now.time + 1));
                a[nx][ny] = now.virus;
            }
        }
    }
    
    static boolean isOut(int x, int y) {
        return (x < 1 || x > n || y < 1 || y > n);
    }
}