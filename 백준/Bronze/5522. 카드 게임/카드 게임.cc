#include <bits/stdc++.h>
using namespace std;

int num, sum;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++) {
        cin >> num;
        sum += num;
    }

    cout << sum;
}