#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        string a_str = to_string(a);
        string b_str = to_string(b);
        
        return stoi(a_str + b_str) > stoi(b_str + a_str);
    });
    
    if(to_string(numbers[0]) == "0") {
        return "0";
    }
    
    for(int number : numbers) {
        answer += to_string(number);
    }
    
    return answer;
}