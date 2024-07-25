import java.util.*;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<String> letterLogs = new ArrayList<>();
        List<String> digitLogs = new ArrayList<>();
        
        for(String log : logs) {
            if(Character.isLetter(log.split(" ")[1].charAt(0))) {   // Letter-logs인지 확인
                letterLogs.add(log);
            } else {
                digitLogs.add(log);
            }
        }
        
        Collections.sort(letterLogs, (o1, o2) -> {
            String[] log1 = o1.split(" ", 2);   // 첫번째 공백을 기준으로 2구역으로 나눔
            String[] log2 = o2.split(" ", 2);
            
            int compared = log1[1].compareTo(log2[1]);
            if(compared == 0) {
                return log1[0].compareTo(log2[0]);
            }          
            return compared;
        });
        
        String[] answer = new String[logs.length];
        int idx = 0;
        
        for(String log : letterLogs) {
            answer[idx++] = log;
        }
        
        for(String log : digitLogs) {
            answer[idx++] = log;
        }
        
        return answer;
    }
}