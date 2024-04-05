import java.io.*;
import java.util.*;

class Lecture {
    int S;
    int T;
    
    public Lecture(int S, int T) {
        this.S = S;
        this.T = T;
    }
}

public class Main {
    public static void main(String args[]) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      int N = Integer.parseInt(br.readLine());
      Lecture[] lectures = new Lecture[N];
      
      for(int i = 0; i < N; i++) {
          StringTokenizer st = new StringTokenizer(br.readLine());
          
          int S = Integer.parseInt(st.nextToken());
          int T = Integer.parseInt(st.nextToken());
          
          lectures[i] = new Lecture(S, T);
      }
      
      Arrays.sort(lectures, (o1, o2) -> o1.S - o2.S);
      
      PriorityQueue<Integer> pq = new PriorityQueue<>();    // 종료시간을 오름차순으로 정렬한 우선순위 큐
      
      for(int i = 0; i < N; i++) {
          if(!pq.isEmpty() && pq.peek() <= lectures[i].S) {
              pq.poll();
          }
          pq.offer(lectures[i].T);
      }
      
      System.out.println(pq.size());
      
      br.close();
    }
}