class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase().replaceAll("[^a-z0-9]+", "");
        
        String reverse = new StringBuilder(s).reverse().toString();
        
        return s.equals(reverse);
    }
}