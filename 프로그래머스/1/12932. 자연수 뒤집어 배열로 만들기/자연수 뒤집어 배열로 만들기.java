class Solution {
    public int[] solution(long n) {
        String s = Long.toString(n);
        String revS = new StringBuilder(s).reverse().toString();
        int[] answer = new int[s.length()];
        
        for(int i = 0; i < revS.length(); i++) {
            answer[i] = revS.charAt(i) - '0';
        }
        
        return answer;
    }
}