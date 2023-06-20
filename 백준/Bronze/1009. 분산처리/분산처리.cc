#include <bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;

        int num = 1;
        for(int i = 0; i < b; i++)
            num = num * a % 10;
        
        if(num == 0) {
            cout << 10 << '\n';
            continue;
        }

        cout << num << '\n';

    }
}