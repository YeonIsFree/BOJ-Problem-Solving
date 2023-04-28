#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int input[10];

void func(int k, int st) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    int prev_last = 0;
    for(int i = st; i < n; i++) {
        if(prev_last == input[i]) continue;
        arr[k] = input[i];
        prev_last = arr[k];
        func(k+1, i);
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