#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    
    answer += toupper(s[0]);
    for(int i = 1; i < len; i++) {
        if(s[i-1] == ' ') answer += toupper(s[i]);
        else answer += tolower(s[i]);
    }
    
    return answer;
}