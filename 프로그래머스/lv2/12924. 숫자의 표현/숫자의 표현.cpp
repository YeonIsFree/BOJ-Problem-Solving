#include <bits/stdc++.h>
using namespace std;

// 투포인터
int solution(int n) {
    int sum = 1;
    int cnt = 1;
    
    int st = 1, en = 1;
    while(en != n) {
        if(sum > n) {
            sum -= st;
            st++;
        }
        else if(sum < n) {
            en++;
            sum += en;
        }
        else if(sum == n) {
            cnt++;
            en++;
            sum += en;
        }
    }
    return cnt;
}