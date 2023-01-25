#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int a[9]; // 난쟁이 후보들 전체의 키를 담은 배열
int sum;
vector<int> V; // 진짜 난쟁이들의 키를 담은 배열
pair<int, int> ret; // 가짜 난쟁이들 {가짜1, 가짜2}

void solve() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < i; j++) {
            if(sum - a[i] - a[j] == 100) {
                ret = {i, j};
                return;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 9; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    solve(); // 난쟁이 아닌 2명 색출, ret에 그 둘의 인덱스를 담는다.

    for(int i = 0; i < 9; i++) {
        // 가짜 녀석들은 거르고 진짜 난쟁이들만 V에 넣어줌
        if(ret.X == i || ret.Y == i) continue;
        V.push_back(a[i]);
    }

    sort(V.begin(), V.end());

    for(int i : V) cout << i << '\n';

    return 0;
}