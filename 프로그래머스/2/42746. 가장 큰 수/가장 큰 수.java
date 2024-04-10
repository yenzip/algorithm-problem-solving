import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        List<String> sNumbers = new ArrayList<>();
        
        for(int number : numbers) {
            sNumbers.add(String.valueOf(number));
        }
        
        Collections.sort(sNumbers, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < sNumbers.size(); i++) {
            sb.append(sNumbers.get(i));
        }
        
        return sb.charAt(0) == '0' ? "0" : sb.toString();
    }
}