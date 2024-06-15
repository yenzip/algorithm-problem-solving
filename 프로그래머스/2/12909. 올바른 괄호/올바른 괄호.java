import java.util.*;

class Solution {
    boolean solution(String s) {
        Deque<Character> stk = new ArrayDeque<>();

        for(char c : s.toCharArray()) {
            if(c == '(') {
                stk.offer(c);
            } else {    // c == ')'
                if(stk.isEmpty()) {
                    return false;
                } 
                stk.pollLast();
            }
        }

        return stk.isEmpty();
    }
}