#include <bits/stdc++.h>
using namespace std;

int t, n, m;

bool is_most_important(map<int, int> D, queue<int> Q, int cur) {
    vector<int> idx;    // 남아있는 문서 번호들
    while(!Q.empty()) {
        idx.push_back(Q.front());
        Q.pop();
    }

    for(int i : idx) {
        if(i == cur) continue;
        if(D[i] > D[cur]) return false;
    }

    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        vector<int> ans; // 출력 순서를 담은 배열
        queue<int> Q;    // 프린터 큐
        map<int, int> D; // {문서번호, 중요도} [ex] D[3] = 2 --> 3번 문서의 중요도는 2
        // 입력
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            int p;
            cin >> p;
            D[i] = p; 
        }

        // 문서를 순서대로 Q에 채워준다.
        for(int i = 0; i < n; i++) Q.push(i);

        while(!Q.empty()) {
            int cur = Q.front();
            // 현재 보고 있는 문서가 가장 중요한 경우
            if(is_most_important(D, Q, cur)) {
                ans.push_back(cur);
                Q.pop();
            }
            // 아닌 경우
            else {
                Q.push(cur);
                Q.pop();
            }
        }
        for(int i = 0; i < ans.size(); i++)
            if(ans[i] == m) cout << i + 1 << '\n';
    }
}