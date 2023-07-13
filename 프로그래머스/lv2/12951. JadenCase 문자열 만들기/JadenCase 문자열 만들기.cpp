#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string ans = "";
    bool is_first = true;
    
    for(char c : s) {
        // 공백을 만나면 바로 다음에 단어의 첫글자가 나옴을 표시해주고
        // 공백을 그대로 이어 붙인 후 넘어간다.
        if(c == ' ') {
            ans += c;
            is_first = true;
            continue;
        }
        
        // 1) 첫글자 검사
        if(is_first) {
            // 숫자이거나 대문자라면 그냥 그대로 붙여준다.
            if(isdigit(c) || (int)c <= 90)
                ans += c;

            // 소문자라면 대문자로 변환 후 이어 붙여준다.
            else if(97 <= (int)c && (int)c <= 122)
                ans += (char)(c - 32);
            
            // 첫글자 검사 완료. 표시를 false 로 바꿔주고 다음 문자들 검사.
            is_first = false;
            continue;
        }
        
        // 2) 첫글자가 아닌 문자를 검사
        if(!is_first) {
            // 첫글자가 아닌데 대문자이면 소문자로 변환 후 이어 붙여준다.
            if(65 <= (int)c && (int)c <= 90)
                ans += char(c + 32);
            // 소문자면 그냥 그대로 이어 붙여준다.
            else ans += c;     
        }
    }
    
    return ans;
    
}