#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    // 길이 검사
    int len = s.size();
    if(len != 4 && len != 6) return false;
    
    // 숫자로 구성되어있는지 검사
    for(char c : s) {
        if(c - 'A' >= 0) return false; 
    }
    
    return true;
}