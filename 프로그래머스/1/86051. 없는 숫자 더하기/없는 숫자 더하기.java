class Solution {
    public int solution(int[] numbers) {
        int answer = 0;
        boolean[] flag = new boolean[10];
        
        for(int num : numbers) {
            if(!flag[num]) {
                flag[num] = true;
            }
        }
        
        for(int i = 0; i < 10; i++) {
            if(!flag[i]) {
                answer += i;
            }
        }
        
        return answer;
    }
}