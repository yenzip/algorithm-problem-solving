import java.util.*;

class Solution {
    public int[] solution(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int min = Arrays.stream(arr).min().orElse(0);
        
        for(int x : arr) {
            if(x == min) {
                continue;
            }
            list.add(x);
        }
        
        if(list.size() == 0) {
            list.add(-1);
        }
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}