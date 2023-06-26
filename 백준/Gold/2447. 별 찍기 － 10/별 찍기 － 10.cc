#include <bits/stdc++.h>
using namespace std;

int n;

void draw(int x, int y, int n) {
    if(x % 3 == 1 && y % 3 == 1) cout << " ";
    else if(n / 3 == 1) cout << "*";
    else draw(x / 3, y / 3, n / 3); 
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            draw(i, j, n);
        }
        cout << '\n';
    }
}