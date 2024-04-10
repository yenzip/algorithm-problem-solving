#include <bits/stdc++.h>
using namespace std;

bool comp(const string &a, const string &b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";   
    vector<string> sNumbers;
    
    for(int number : numbers) {
        sNumbers.push_back(to_string(number));
    }
    
    sort(sNumbers.begin(), sNumbers.end(), comp);
    
    if(sNumbers[0] == "0") {
        return "0";
    }
    
    for(int i = 0; i < sNumbers.size(); i++) {
        answer += sNumbers[i];
    }
    
    return answer;
}