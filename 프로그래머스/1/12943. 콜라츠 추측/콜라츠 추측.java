class Solution {
    public int collatz(long num, int cnt) {
        if (num == 1) {
            return cnt;
        }
        
        if (cnt >= 500) {
            return -1;
        }
        
        return collatz(num % 2 == 0 ? num / 2 : num * 3 + 1, cnt + 1);
    }
    
    public int solution(int num) {
        if(num == 1) {
            return 0;
        }
        
        return collatz(num, 0);
    }
}