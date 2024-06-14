class Solution {
    boolean solution(String s) {
        // * toLowerCase(): 문자열 소문자로 변환
        s = s.toLowerCase();
        
        int p = 0;
        int y = 0;
        
        for(char c : s.toCharArray()) {
            if(c == 'p') {
                p++;
            }
            if(c == 'y') {
                y++;
            }
        }

        return p == y;
    }
}