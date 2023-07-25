#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> S;
    
    for(char c : s) {
        if(S.empty()) { 
            S.push(c);
            continue;
        }
        
        if(c == S.top()) S.pop();
        else S.push(c);
    }
    
    answer = S.empty()? 1 : 0;
    
    return answer;
}