#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> S;
    
    for(char c : s) {
        if(S.empty()) {
            S.push(c);
            continue;
        }
        
        if(c == ')') {
            if(S.top() == '(') S.pop();
            else S.push(c);
        }
        else if(c == '(') S.push(c);
    }
    
    if(S.empty()) answer = true;
    else answer = false;

    return answer;
}