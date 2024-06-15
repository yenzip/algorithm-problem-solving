import java.util.*; 

class Solution {
    public int[] solution(int[] prices) {
        int[] answer = new int[prices.length];
        
        for(int i = 0; i < prices.length - 1; i++) {
            Queue<Integer> q = new LinkedList<>();
            
            for(int j = i + 1; j < prices.length; j++) {
                q.offer(j);
                
                if(prices[i] > prices[j]) {
                    break;
                } 
            }
            
            answer[i] = q.size();
            q.clear();
        }
        
        return answer;
    }
}