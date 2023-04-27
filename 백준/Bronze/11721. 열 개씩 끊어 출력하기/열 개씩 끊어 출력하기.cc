#include <bits/stdc++.h>
using namespace std;

string s;
int lb, ub;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int Q = s.size() / 10; // 10으로 나눈 몫
    int R = s.size() % 10; // 10으로 나눈 나머지
    for(int n = 0; n < Q; n++) {
        lb = 10 * n;
        ub = 10 * (n+1);
        for(int i = lb; i < ub; i++) 
            cout << s[i];
        cout << '\n';
    }
    for(int n = 10 * Q; n < (10 * Q) + R; n++)
        cout << s[n];
}