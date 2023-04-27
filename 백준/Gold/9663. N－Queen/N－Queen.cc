#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
bool isused_Y[40];   // 열
bool isused_P[40];   // 기울기 양의 방향 대각선
bool isused_N[40];   // 기울기 음의 방향 대각선

// (x, y) = (행, 열)

void func(int x) {
    /*
        결국 한 행에 하나씩 밖에 둘 수 없으므로,행을 기준으로 본다.
    */

    // base condition - 서로를 피해서 착수 성공
    if(x == n) {
        cnt++;
        return;
    }
    // main logic 
    for(int y = 0; y < n; y++) { // (x, y)
        if(isused_Y[y] || isused_P[x+y] || isused_N[x-y+n-1]) continue;
        // 해당 위치에 놓을 수 없음을 표시
        isused_Y[y] = 1;
        isused_P[x+y] = 1;
        isused_N[x-y+n-1] = 1;
        func(x+1);
        // 원상복귀
        isused_Y[y] = 0;
        isused_P[x+y] = 0;
        isused_N[x-y+n-1] = 0;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}