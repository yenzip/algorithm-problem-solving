import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 1;
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 0; i < priorities.length; i++) {
            pq.offer(priorities[i]);
            q.offer(i);
        }
        
        while(!pq.isEmpty()) {
            int p = pq.poll();
            
            while(!q.isEmpty()) {
                int idx = q.poll();
                
                if(priorities[idx] == p) {
                    if(idx == location) {
                        return answer;
                    }
                    answer++;
                    break;
                }
                
                q.offer(idx);
            }
        }
        
        return answer;
    }
}