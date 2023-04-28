#include <bits/stdc++.h>
using namespace std;

int num;
int a, b; // 최대 좌표를 저장할 변수
int mx; // 최대값

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> num;
            if(num > mx) {
                mx = num;
                a = i;
                b = j;
            }
        }
    }
    cout << mx << '\n';
    cout << a+1 << ' ' << b+1;
    return 0;
}