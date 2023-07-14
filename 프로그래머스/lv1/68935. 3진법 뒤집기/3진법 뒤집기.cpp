#include <bits/stdc++.h>
using namespace std;

int ans;

int solution(int n) {
    
    // 3진법으로 변환 (거꾸로 된 상태)
    string tmp = "";
    while(n > 0) {
        tmp += to_string(n % 3);
        n /= 3;
    }
    
    // 
    int digit = 1;
    int len = tmp.size();
    for(int i = len-1; i >= 0; i--) {
        int num = tmp[i] - '0';
        ans += num * digit;
        digit *= 3;
    }
    
    return ans;
    
}