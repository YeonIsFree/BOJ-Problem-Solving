#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<>> Q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        int com;
        cin >> com;
        if(com == 0) {
            if(Q.empty()) cout << 0 << '\n';
            else {
                cout << Q.top() << '\n';
                Q.pop();
            }
        }
        else Q.push(com);
    }
}