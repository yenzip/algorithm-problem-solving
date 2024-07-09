#include <bits/stdc++.h>
using namespace std;

int N;
map<string, int> friend_map;
int give[50][50];           // give[i][j]: 이번 달 i번 친구가 j번 친구에게 선물을 준 횟수
int give_n_take[50];        // 선물 지수: 이번 달 선물을 주고 받은 횟수(주면 ++, 받으면 --)
int next_month[50];         // 다음 달 선물을 받을 횟수

int solution(vector<string> friends, vector<string> gifts) {    
    N = friends.size();
    
    for(int i = 0; i < N; i++) {
        friend_map[friends[i]] = i;
    }
    
    for(string gift : gifts) {  // 이번 달 선물 주고 받은 기록 확인하기
        stringstream ss(gift);
        string giver, taker;
        ss >> giver >> taker;
        
        int g = friend_map[giver];
        int t = friend_map[taker];
        
        give[g][t]++;
        give_n_take[g]++;
        give_n_take[t]--;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(give[i][j] > give[j][i]) {
                next_month[i]++;
            } else if(give[i][j] < give[j][i]) {    // 다음 달 A가 B에게 선물 주기
                next_month[j]++;
            } else {
                if(give_n_take[i] > give_n_take[j]) {
                    next_month[i]++;
                } else if(give_n_take[i] < give_n_take[j]) {
                    next_month[j]++;
                }
            }
        }
    }

    int answer = *max_element(next_month, next_month + N);
    
    return answer;
}