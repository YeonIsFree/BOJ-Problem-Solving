#include <bits/stdc++.h>
using namespace std;

long long fact[22];

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> num;
    
    // 숫자 배열
    for(int i = 1; i <= n; i++) num.push_back(i);
    
    // 팩토리얼 미리 계산
    fact[0] = 1;
    for(int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
    
    // -----
    k--;
    while(n > 0) {
        int first_idx = k / fact[n-1];
        answer.push_back(num[first_idx]);
        num.erase(num.begin() + first_idx);
        k %= fact[n-1];
        n--;
    }
    return answer;
}