#include <bits/stdc++.h>
using namespace std;

int checkOverHealth(int now_health, int max_health) {
    return now_health > max_health ? max_health : now_health;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;        // 현재 체력
    int idx = 0;                // 공격 인덱스
    int time = 1;               // 시간
    int success = 1;            // 연속 성공
    
    int t = bandage[0];         // 시전 시간
    int x = bandage[1];         // 초당 회복량
    int y = bandage[2];         // 추가 회복량
    
    while(idx < attacks.size() && answer > 0) {
        if(attacks[idx][0] == time) {
            answer -= attacks[idx][1];
            idx++;
            success = 0;
        } else {
            if(success == bandage[0]) {
                answer = checkOverHealth(answer + x + y, health);
                success = 0;
            } else {
                answer = checkOverHealth(answer + x, health);
            }
        }
        time++;
        success++;
    }
    
    cout << answer << endl;
    
    return answer <= 0 ? -1 : answer;
}