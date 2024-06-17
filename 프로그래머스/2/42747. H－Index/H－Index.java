import java.util.*;

class Solution {
    public int solution(int[] citations) {
        int answer = citations.length;
        // cf) primitive type의 경우 Collections.reverseOrder() 사용 불가!!
        Arrays.sort(citations);
        
        for(int i = 0; i < citations.length; i++, answer--) {
            if(answer <= citations[i]) {
                break;
            }
        }  
        
        return answer;
    }
}