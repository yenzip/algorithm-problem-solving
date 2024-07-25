class Solution {
    public void reverseString(char[] s) {
        String tmp = String.valueOf(s);
        int len = s.length;
        
        for(int i = 0; i < len; i++) {
            s[i] = tmp.charAt(len - i - 1);
        }
    }
}