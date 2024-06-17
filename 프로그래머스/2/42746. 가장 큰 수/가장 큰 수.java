import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        // int 배열을 String 배열로 변환하는 방법: Stream 사용
        String[] arr = Arrays.stream(numbers).mapToObj(String::valueOf).toArray(String[]::new);
        
        // 람다식을 사용해 내림차순 사용자 정렬하기
        // 문자열 비교: compareTo(s1, s2)
        Arrays.sort(arr, (o1, o2) -> (o2 + o1).compareTo(o1 + o2));
        
        // String 배열을 String으로 변환하기: join(delim, arr)
        // [Error] String 배열의 모든 원소가 0인 경우 예외 처리하기
        return arr[0].equals("0") ? "0" : String.join("", arr);
    }
}