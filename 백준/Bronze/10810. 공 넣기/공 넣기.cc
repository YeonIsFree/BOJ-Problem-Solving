#include <bits/stdc++.h>
using namespace std;

int n, m;
int s, e, num;
int arr[103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> s >> e >> num;
        for(int i = s; i <= e; i++) 
            arr[i] = num;
    }
    for(int i = 1; i <= n; i++) {
        cout << arr[i] << ' ';
    }
}