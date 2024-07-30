class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.toLowerCase().split("[^\\w]+");
        Set<String> st = new HashSet<>();
        Map<String, Integer> m = new HashMap<>();
        
        for(String ban : banned) {
            st.add(ban);
        }
        
        for(String word : words) {
            if(st.contains(word)) {
                continue;
            }
            
            m.put(word, m.getOrDefault(word, 0) + 1);
        }
        
        String answer = "";
        int maxCount = 0;
        
        for(String key : m.keySet()) {
            int value = m.get(key);
            if(maxCount < value) {
                answer = key;
                maxCount = value;
            }
        }
        
        return answer;
    }
}