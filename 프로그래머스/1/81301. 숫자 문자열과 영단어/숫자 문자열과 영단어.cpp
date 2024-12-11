#include <regex>
using namespace std;

int solution(string s) {

    /**
    [문자열 치환]
    - #include <regex>
    - regex_replace(대상 문자열, regex(치환될 문자열), 치환할 문자열)
    **/
    
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");
    
    return stoi(s);
}