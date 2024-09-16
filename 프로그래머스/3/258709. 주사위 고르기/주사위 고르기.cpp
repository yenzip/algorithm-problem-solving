#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> A, B;
vector<int> answer;
int maxWin;

void dfs(vector<vector<int>> dice, vector<int> team, vector<int> &pip, int index, int sum) {
    if(index == n / 2) {
        pip.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++) {
        sum += dice[team[index]][i];
        dfs(dice, team, pip, index + 1, sum);
        sum -= dice[team[index]][i];
    }
}

int calculate(vector<int> pipA, vector<int> pipB) { 
    int win = 0;
    
    sort(pipA.begin(), pipA.end());
    sort(pipB.begin(), pipB.end());
    
    for(int sum : pipA) {
        win += lower_bound(pipB.begin(), pipB.end(), sum) - pipB.begin();
    }
    
    return win;
}

void combination(vector<vector<int>> dice, int index) {
    if(A.size() > n / 2 || B.size() > n / 2) {
        return;
    }
    if(index == n) {
        // A 주사위 눈의 합 구하기
        vector<int> pipA;
        dfs(dice, A, pipA, 0, 0);
        // B 주사위 눈의 합 구하기
        vector<int> pipB;
        dfs(dice, B, pipB, 0, 0);
        
        // 이분탐색을 활용해 A가 이길 확률 구하기
        int win = calculate(pipA, pipB);
        if(maxWin < win) {
            answer = A;
            maxWin = win;
        }
        return;
    }
    
    // A 선택
    A.push_back(index);
    combination(dice, index + 1);
    A.pop_back();
    
    // B 선택
    B.push_back(index);
    combination(dice, index + 1);
    B.pop_back();
}

vector<int> solution(vector<vector<int>> dice) {
    
    n = dice.size();
    
    combination(dice, 0);
    
    for(int i = 0; i < n / 2; i++) {
        answer[i]++;
    }
       
    return answer;
}