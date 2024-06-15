import java.util.*;

class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<>();  // 다리(bridge)
        
        for(int i = 0; i < bridge_length; i++) {
            q.offer(0);
        }
        
        int i = 0;
        int total_weight = 0;
        
        while(i < truck_weights.length) {
            total_weight -= q.poll();
            
            if(total_weight + truck_weights[i] > weight) {
                q.offer(0);
            } else {
                q.offer(truck_weights[i]);
                total_weight += truck_weights[i++];
            }
            
            answer++;
        }
        
        answer += q.size();
        
        return answer;
    }
}