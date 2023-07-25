#include <bits/stdc++.h>
using namespace std;

int ans;
bool isused_Y[40]; // y축 좌표 체크
bool isused_P[40]; // 양의 방향 대각선 체크
bool isused_N[40]; // 음의 방향 대각선 체크

void func(int x, int n) {
    if(x == n) {
        ans++;
        return;
    }
    
    for(int y = 0; y < n; y++) {
        if(isused_Y[y] || isused_P[x+y] || isused_N[x-y+n-1]) 
            continue;
        isused_Y[y] = true;
        isused_P[x+y] = true;
        isused_N[x-y+n-1] = true;
        func(x+1, n);
        isused_Y[y] = false;
        isused_P[x+y] = false;
        isused_N[x-y+n-1] = false;
    }
}

int solution(int n) {
    func(0, n);
    return ans;
}