import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        List<Integer> list = new ArrayList<>();
        
        for(int[] command : commands) {
            int i = command[0];
            int j = command[1];
            int k = command[2];
            
            // 배열 자르기: Arrays.copyOfRange(배열, 시작 인덱스, 종료 인덱스)
            int[] arr = Arrays.copyOfRange(array, i - 1, j);
            Arrays.sort(arr);
            
            list.add(arr[k - 1]);
        }
        
        return list.stream().mapToInt(Integer::intValue).toArray();
    }
}