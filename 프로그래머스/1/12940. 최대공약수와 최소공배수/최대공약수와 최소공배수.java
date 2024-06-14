class Solution {
    public int getGcd(int a, int b) {
        if(b == 0) {
            return a;
        }     
        return getGcd(b, a % b);
    }
    
    public int[] solution(int n, int m) {
        int gcd = getGcd(n, m);
        int lcd = n * m / gcd;
        
        return new int[]{gcd, lcd};
    }
}