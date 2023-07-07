#include <bits/stdc++.h>
using namespace std;

int n, w, l;
queue<int> T;
queue<int> B;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력
    cin >> n >> w >> l;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        T.push(tmp);
    }

    // -----
    int sec = 0;
    int sum = 0;
    while(!T.empty()) {
        int t = T.front(); // 현재 보고 있는 트럭 무게

        if(B.size() == w) {
            sum -= B.front();
            B.pop();
        }

        // 다리에 올라갈 수 있는 경우
        if(sum + t <= l) {
            T.pop();
            B.push(t);
            sum += t;
            sec++;
            continue;
        }

        // 다리에 올라갈 수 없는 경우
        if(sum + t > l) {
            B.push(0);
            sec++;
            continue;
        }
        sec++;
    }

    cout << sec + w;

}