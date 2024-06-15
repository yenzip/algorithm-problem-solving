import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        Deque<Integer> stk = new ArrayDeque<>();
        
        for(int x : arr) {
            if(!stk.isEmpty() && stk.peekLast() == x) {
                continue;
            }
            stk.offer(x);
        }

        return stk.stream().mapToInt(Integer::intValue).toArray();
    }
}