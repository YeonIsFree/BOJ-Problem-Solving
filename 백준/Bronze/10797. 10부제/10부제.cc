#include <bits/stdc++.h>
using namespace std;

int d;
int num[5];
int cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> d;
    for(int i = 0; i < 5; i++) {
        cin >> num[i];
        if(num[i] == d) cnt++;
    }
    cout << cnt;
}