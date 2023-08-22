#include <bits/stdc++.h>
using namespace std;

int n;
int arr[52];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    // ----
    int cnt = 0;
    priority_queue<int> PQ;
    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 1; i < n; i++) PQ.push(arr[i]);

    while(PQ.top() >= arr[0]) {
        cnt++;
        int target = PQ.top() - 1;
        PQ.pop();
        PQ.push(target);
        arr[0]++;
    }
    cout << cnt;
}