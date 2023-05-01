#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 입력
    cin >> n >> m;
    
    vector<int> arr(n);
    // 바구니 채워 넣기
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        reverse(arr.begin()+a-1, arr.begin()+b);
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
   
}