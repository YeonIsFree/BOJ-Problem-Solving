#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int len = s.size();
    int mid = len / 2;
    
    if(len % 2 == 0) { // 길이가 짝수일 경우
        string ans = s.substr(mid - 1, 2);
        return ans;
    }
    else {             // 길이가 홀수일 경우
        string ans = s.substr(mid, 1);
        return ans;
    }

}