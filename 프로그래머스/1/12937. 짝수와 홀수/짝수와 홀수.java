class Solution {
    public String solution(int num) {
        // [Error] -1인 경우 고려 필요
        return (Math.abs(num) % 2 == 1) ? "Odd" : "Even";
    }
}