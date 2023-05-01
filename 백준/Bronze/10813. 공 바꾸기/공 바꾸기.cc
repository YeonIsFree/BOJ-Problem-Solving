#include <bits/stdc++.h>
using namespace std;

int n, m;
int a, b, temp;
int arr[103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i < n+1; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        // 예를들어  arr[5] = 5
        // arr[4] = 4
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    for(int i = 1; i < n+1; i++) 
        cout << arr[i] << ' ';
}