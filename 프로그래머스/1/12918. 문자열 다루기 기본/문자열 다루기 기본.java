class Solution {
    public boolean solution(String s) {
        int len = s.length();
        
        if(len != 4 && len != 6) {
            return false;
        }
        
        for(char c : s.toCharArray()) {
            if(!Character.isDigit(c)) {
                return false;
            }
        }
        
        return true;
    }
}