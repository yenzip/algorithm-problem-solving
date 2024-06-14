class Solution {
    public int getDigitSum(int x) {
        int sum = 0;
        
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
        
        return sum;
    }
    
    public boolean solution(int x) {
        return x % getDigitSum(x) == 0;
    }
}