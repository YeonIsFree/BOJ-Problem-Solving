#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i < n; i++) {
        int target = i;
        int sum = target;

        while(target > 0) {
            sum += target % 10;
            target /= 10;
        }

        if(sum == n) {
            cout << i << '\n';
            return 0;
        }
    }

     cout << 0;
}