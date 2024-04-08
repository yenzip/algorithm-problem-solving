import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
        int N = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();
    
        for(int i = 0; i < N; i++) {
            String[] A = br.readLine().split(" ");
            
            for(int j = 0; j < N; j++) {
                pq.offer(Integer.parseInt(A[j]));
                
                if(pq.size() > N) {
                    pq.poll();
                }
            }
        }
        
        System.out.println(pq.peek());
        
        br.close();
    }
}