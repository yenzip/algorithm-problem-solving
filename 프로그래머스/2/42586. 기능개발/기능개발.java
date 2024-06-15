import java.util.*;

class Solution {
    private int calculateRemainingDays(int progress, int speed) {
        int days = (100 - progress) / speed;
        return (100 - progress) % speed == 0 ? days : days + 1;
    }
    
    public int[] solution(int[] progresses, int[] speeds) {
        List<Integer> list = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        
        for(int i = 0; i < progresses.length; i++) {
            int days = calculateRemainingDays(progresses[i], speeds[i]);
            
            if(!q.isEmpty() && q.peek() < days) {
                list.add(q.size());
                q.clear();
            }
            
            q.offer(days);
        }
        
        list.add(q.size());
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}