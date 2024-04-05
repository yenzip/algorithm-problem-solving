import java.io.*;
import java.util.*;

class Lecture {
    int S;
    int T;
    
    Lecture(int S, int T) {
        this.S = S;
        this.T = T;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        Lecture[] lectures = new Lecture[N];
        for (int i = 0; i < N; ++i) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            lectures[i] = new Lecture(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        
        Arrays.sort(lectures, (a, b) -> Integer.compare(a.S, b.S));
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(Lecture lecture : lectures) {
            if(!pq.isEmpty() && pq.peek() <= lecture.S) {
                pq.poll();
            }
            pq.offer(lecture.T);
        }
        
        System.out.println(pq.size());
        br.close();
    }
}