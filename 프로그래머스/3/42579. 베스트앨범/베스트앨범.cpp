#include <bits/stdc++.h>
using namespace std;

struct Song {   // 노래 정보
    int num;
    int play;
    
    bool operator<(const Song &other) const {
        if(play == other.play) {
            return num > other.num;
        }
        return play < other.play;
    }
};

map<string, int> mSum;    // 장르별 재생횟수의 합
map<string, vector<Song>> mSong;    // 장르별 노래 정보

bool comp(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i = 0; i < genres.size(); i++) {
        mSum[genres[i]] += plays[i];
        mSong[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> sum(mSum.begin(), mSum.end());
    sort(sum.begin(), sum.end(), comp);
    
    for(auto s : sum) {
        string genre = s.first;
        priority_queue<Song> pq(mSong[genre].begin(), mSong[genre].end());
        
        answer.push_back(pq.top().num);
        pq.pop();
        
        if(!pq.empty()) {
            answer.push_back(pq.top().num);
        }
    }
    
    return answer;
}