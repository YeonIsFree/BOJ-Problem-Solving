#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 오름차순에서 순서대로 더해나간다.
    priority_queue<int, vector<int>, greater<int>> Q;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Q.push(x);
    }

    int sum = 0;
    while(Q.size() != 1) {
        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();
        sum += (a + b);
        Q.push(a+b);
    }
    cout << sum;
}