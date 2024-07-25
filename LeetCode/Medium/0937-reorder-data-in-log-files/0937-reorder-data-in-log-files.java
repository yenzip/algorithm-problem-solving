import java.util.*;

class Solution {
    public String[] reorderLogFiles(String[] logs) {
        List<Log> letterLogs = new ArrayList<>();
        List<String> digitLogs = new ArrayList<>();
        
        for(String log : logs) {
            String identifier = log.split(" ")[0];
            String word = log.substring(identifier.length() + 1);
            
            if(Character.isDigit(word.charAt(0))) {
                digitLogs.add(log);
            } else {
                letterLogs.add(new Log(identifier, word, log));
            }
        }
        
        Collections.sort(letterLogs, (o1, o2) -> {
            if(o1.word.equals(o2.word)) {
                return o1.identifier.compareTo(o2.identifier);
            }
            return o1.word.compareTo(o2.word);
        });
        
        String[] answer = new String[logs.length];
        int idx = 0;
        
        for(Log e : letterLogs) {
            answer[idx++] = e.log;
        }
        
        for(String s : digitLogs) {
            answer[idx++] = s;
        }
             
        return answer;
    }
    
    static class Log {
        String identifier;
        String word;
        String log;
        
        Log(String identifier, String word, String log) {
            this.identifier = identifier;
            this.word = word;
            this.log = log;
        }
    }
}