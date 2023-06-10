#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int st = 1, en = 1, sum = 1, cnt = 1;
    while(en != n) {
        if(sum > n) {
            sum -= st;
            st++;
        }
        else if(sum < n) {
            en++;
            sum += en;
        }
        else {
            cnt++;
            sum -= st;
            st++;
        }
    }
    cout << cnt;
}