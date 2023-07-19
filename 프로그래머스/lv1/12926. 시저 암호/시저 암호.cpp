#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(char c : s) {
        // 공백일 경우
        if(c == ' ') {
            answer += c;
            continue;
        }
        
        int num = c + n;
        // 소문자일 경우
        if(islower(c))
            answer += 'a' + ( (num - 'a') % 26 );
        
        // 대문자일 경우
        else if(isupper(c))
            answer += 'A' + ( (num - 'A') % 26 );
            
    }
    return answer;
}