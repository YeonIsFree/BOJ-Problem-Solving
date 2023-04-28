#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    // 중복 허용
    // 같은 수열은 안됨
    int prev_last = 0;
    for(int i = 0; i < n; i++) {
        if(prev_last == input[i]) continue;
        arr[k] = input[i];
        prev_last = arr[k];
        func(k+1, i+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input+n);
    func(0, 0);
}