import java.io.*;
import java.util.*;

class Solution { 
    private Map<String, List<Integer>> map;

    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        
        map = new HashMap<>();
        
        for(String i : info) {
            String[] s = i.split(" ");
            makeCondition(s, 0, new StringBuilder());    // 지원 정보로 만들 수 있는 모든 경우(조건)의 수 구하기
        }
        
        for(String key : map.keySet()) {  // 각 조건 별로 점수를 정렬하기
            Collections.sort(map.get(key));
        }
        
        for(int i = 0; i < query.length; i++) {
            query[i] = query[i].replaceAll(" and ", "");
            String[] s = query[i].split(" ");
            int score = Integer.parseInt(s[1]);
            if(map.containsKey(s[0])){  // 키가 존재하는지 확인 후    
                answer[i] = binarySearch(map.get(s[0]), score); // 이분탐색을 통한 score 점수 이상의 지원자 수 구하기
            }
        }  
        
        return answer;
    }
    
    private void makeCondition(String[] s, int i, StringBuilder sb) {
        if(i == 4) {
            map.computeIfAbsent(sb.toString(), v -> new ArrayList<>()).add(Integer.parseInt(s[4]));
            return;
        }
        
        makeCondition(s, i + 1, sb.append(s[i]));
        sb.setLength(sb.length() - s[i].length());
        
        makeCondition(s, i + 1, sb.append("-"));
        sb.setLength(sb.length() - 1);
    }
    
    private int binarySearch(List<Integer> sc, int score) {
        int start = 0;
        int end = sc.size() - 1;
        
        while(start <= end) {
            int mid = (start + end) / 2;
            
            if(sc.get(mid) >= score) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        
        return sc.size() - start;
    }
    
}