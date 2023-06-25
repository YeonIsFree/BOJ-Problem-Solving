#include <bits/stdc++.h>
using namespace std;

int sum, ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        int tmp;
        cin >> tmp;
        if(tmp < 40) tmp = 40;
        sum += tmp;
    }
    
    ans = sum / 5;

    cout << ans;
}