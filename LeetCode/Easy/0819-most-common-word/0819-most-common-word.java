class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.toLowerCase().split("[!?',;.\s]+");      
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();
        
        for(String b : banned) {
            set.add(b);
        }
        
        for(String word : words) {
            if(set.contains(word)) {
                continue;
            }
            map.put(word, map.getOrDefault(word, 0) + 1);
        }
        
        return Collections.max(map.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}