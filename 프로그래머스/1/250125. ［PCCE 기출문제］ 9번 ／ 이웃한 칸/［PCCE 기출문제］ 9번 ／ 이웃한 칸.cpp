#include <bits/stdc++.h>
using namespace std;

int n, answer;  // answer = count
int dh[4] = {0, 1, -1, 0};
int dw[4] = {1, 0, 0, -1};

bool isOut(int h, int w) {
    return (h < 0 || h >= n || w < 0 || w >= n);
}

int solution(vector<vector<string>> board, int h, int w) {
    n = board.size();
    
    for(int i = 0; i < 4; i++) {
        int h_check = h + dh[i];
        int w_check = w + dw[i];
        
        if(!isOut(h_check, w_check) && board[h][w] == board[h_check][w_check]) {
            answer++;
        }
    }
    
    return answer;
}