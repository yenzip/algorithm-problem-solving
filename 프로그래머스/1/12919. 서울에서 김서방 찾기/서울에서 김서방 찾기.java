import java.util.*;

class Solution {
    public String solution(String[] seoul) {
        // List로 변환 후 indexOf로 찾기
        int index = Arrays.asList(seoul).indexOf("Kim");
        
        return "김서방은 " + index + "에 있다";
    }
}