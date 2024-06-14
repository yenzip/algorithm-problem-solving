import java.io.*;

class Solution {
    public String solution(String s) {
        int len = s.length();
        int idx = len / 2;
        String answer = s.charAt(idx) + "";
        
        return len % 2 == 0 ? s.charAt(idx - 1) + answer : answer;
    }
}