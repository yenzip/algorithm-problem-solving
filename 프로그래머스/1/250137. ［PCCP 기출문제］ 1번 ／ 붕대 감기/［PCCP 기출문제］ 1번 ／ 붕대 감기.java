import java.io.*;
import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health;    // 현재 체력
        int time = 1;           // 시간
        int success = 1;        // 연속 성공
        int idx = 0;            // 공격 인덱스
        
        int t = bandage[0];     // 시전 시간
        int x = bandage[1];     // 초당 회복량
        int y = bandage[2];     // 추가 회복량
        
        while(idx < attacks.length && answer > 0) {
            if(attacks[idx][0] == time) {
                answer -= attacks[idx][1];
                idx++;
                success = 0;
            } else {
                if(success == t) {
                    answer += y;
                    success = 0;
                }
                answer = checkOverHealth(answer + x, health);
            }
            time++;
            success++;
        }
        
        return answer > 0 ? answer : -1;
    }
    
    private int checkOverHealth(int now, int max_health) {
        return now > max_health ? max_health : now;
    } 
}