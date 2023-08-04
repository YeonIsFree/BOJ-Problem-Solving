#include <bits/stdc++.h>
using namespace std;

int n;
int mn = 98765;
int board1[22][22];
int board2[22][22];

bool OOB(int x, int y, int d1, int d2) {
    if(x + d1 > n || y - d2 > n) return true;
    if(x + d2 > n || y + d2 > n) return true;
    if(x + d1 + d2 > n || y + d2 - d1 > n) return true;
    return false;
}

void mark_district(int x, int y, int d1, int d2) {
    pair<int, int> top = {x, y}; // 기준점
    pair<int, int> left = {x + d1, y - d2}; // 왼쪽
    pair<int, int> right = {x + d2, y + d2}; // 오른쪽
    pair<int, int> bottom = {x + d1 + d2, y + d2 - d1}; // 아래

    // 전체를 5로 채워놓고 시작
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            board2[i][j] = 5;

    // 1번 구역
    int sub = 0;
    for(int i = 1; i < left.first; i++) {
        if(i >= top.first) sub++;
        for(int j = 1; j <= top.second - sub; j++)
            board2[i][j] = 1;
    }

    // 2번 구역
    int add = 0;
    for(int i = 1; i <= right.first; i++) {
        if(i > top.first) add++;
        for(int j = top.second + 1 + add; j <= n; j++)
            board2[i][j] = 2;
    }

    // 3번 구역
    sub = 0;
    for(int i = n; i >= left.first; i--) {
        if(i < bottom.first) sub++;
        for(int j = 1; j < bottom.second - sub; j++)
            board2[i][j] = 3;
    }

    // 4번 구역
    add = 0;
    for(int i = n; i > right.first; i--) {
        if(i <= bottom.first) add++;
        for(int j = bottom.second + add; j <= n; j++)
            board2[i][j] = 4;
    }
}

int cnt() {
    int arr[6] = {0, 0, 0, 0, 0, 0};
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int area = board2[i][j];
            arr[area] += board1[i][j];
        }
    }
    int ret = *max_element(arr+1, arr+6) - *min_element(arr+1, arr+6);
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 입력 
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board1[i][j];

    // -----
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int d1 = 1; d1 <= n; d1++) {
                for(int d2 = 1; d2 <= n; d2++) {
                    if(OOB(i, j, d1, d2)) continue;
                    mark_district(i, j, d1, d2);
                    mn = min(mn, cnt());
                }
            }
        }
    }
    cout << mn;
}