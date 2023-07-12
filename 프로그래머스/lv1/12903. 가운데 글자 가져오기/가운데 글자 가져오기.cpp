#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int len = s.size();
    
    // 길이가 짝수일 경우
    if(len % 2 == 0) {
        string mid = "";
        mid += s[len / 2 - 1];
        mid += s[len / 2];
        return mid;
    }
    
    // 길이가 홀수일 경우
    else {
        string mid = "";
        mid += s[len / 2];
        return mid;
    }

}