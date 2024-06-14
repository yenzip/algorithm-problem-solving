import java.io.*;

class Solution {
    public long solution(long n) {
        // Math.sqrt()의 타입은 double이므로 형변환 필요
        long x = (long) Math.sqrt(n);
        
        return x * x == n ? (x + 1) * (x + 1) : -1;
    }
}