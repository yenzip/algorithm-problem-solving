class Solution {
    public int getNumberOfDivisor(int x) {
        int result = 0;
        
        for(int i = 1; i <= x; i++) {
            if(x % i == 0) {
                result++;
            }
        }
        
        return result;
    }
    
    public int solution(int left, int right) {
        int answer = 0;
        
        for(int i = left; i <= right; i++) {
            answer += (getNumberOfDivisor(i) % 2 == 0 ? i : i * -1);
        }
        
        return answer;
    }
}