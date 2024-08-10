class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        
        for(String str : strs) {
            char[] arr = str.toCharArray();
            Arrays.sort(arr);
            String anagram = new String(arr);   // char 배열 -> String
            map.computeIfAbsent(anagram, key -> new ArrayList<>()).add(str);
        }
        
        List<List<String>> answer = new ArrayList<>();
        
        for(String key : map.keySet()) {
            answer.add(map.get(key));
        }
        
        return answer;
    }
}