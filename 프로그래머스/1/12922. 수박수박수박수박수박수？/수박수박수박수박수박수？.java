class Solution {
    public String solution(int n) {
        String s = "수박";
        int count = n / 2;
        String answer = s.repeat(count);
        
        return n % 2 == 1 ? answer + "수" : answer;
    }
}