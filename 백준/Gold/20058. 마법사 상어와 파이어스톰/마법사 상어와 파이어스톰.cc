#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, q, l;
int ice[65][65];
int ans;

int AREA(int s) {
    queue<pair<int, int>> Q;
    bool vis[s][s];
    for(int i = 0; i < s; i++) fill(vis[i], vis[i]+s, false);
    
    int mx_area = 0;

    for(int i = 0; i < s; i++) {
        for(int j = 0; j < s; j++) {
            if(ice[i][j] == 0 || vis[i][j] == true) continue;
            Q.push({i, j});
            vis[i][j] = true;
            int area = 1;

            while(!Q.empty()) {
                auto cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= s || ny >= s) continue;
                    if(ice[nx][ny] == 0 || vis[nx][ny] == true) continue;
                    Q.push({nx, ny});
                    vis[nx][ny] = true;
                    area++;
                }
            }

            mx_area = max(area, mx_area);
        }
    }

    return mx_area;
}

bool BFS(int x, int y, int s) {
    int cnt = 0;    // 얼음이 없는 칸을 세어줄 변수
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || nx >= s || ny < 0 || ny >= s) {
            cnt++;
            continue;
        }
        if(ice[nx][ny]) continue;
        cnt++;
    }
    if(cnt >= 2) return true;
    return false;
}

void copy(int x, int y, int len, vector<vector<int>> target) {
    for(int i = 0; i < target.size(); i++) {
        for(int j = 0; j < target[i].size(); j++) {
            ice[x+i][y+j] = target[i][j];
        }
    }
}

void rotate90(vector<vector<int>> &target) {
    int len = target.size();
    vector<vector<int>> tmp(len, vector<int>(len, 0));
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            tmp[i][j] = target[len-j-1][i];
        }
    }
    target = tmp;
    return;
}

vector<vector<int>> divider(int x, int y, int len) {
    vector<vector<int>> ret;
    for(int i = x; i < x+len; i++) {
        vector<int> tmp;
        for(int j = y; j < y+len; j++)
            tmp.push_back(ice[i][j]);
        ret.push_back(tmp);
    }
    return ret;
}

void func(int s, int div_s) {
    int unit = s / div_s;
    vector<vector<int>> target;
    for(int i = 0; i < unit; i++) {
        for(int j = 0; j < unit; j++) {
            // 1. 현재 다룰 부분의 배열을 떼어온다.
            target = divider(i * div_s, j * div_s, div_s);

            // 2. 시계 방향으로 90도 회전
            rotate90(target);

            // 3. 돌린 부분을 원본 배열에 갖다 놓는다.
            copy(i * div_s, j * div_s, div_s, target);
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> q;

    int s = 1 << n;         // 전체 격자의 한 변의 길이
    

    for(int i = 0; i < s; i++)
        for(int j = 0; j < s; j++)
            cin >> ice[i][j];
    
    // FIRESTORM 🔥 ------
    for(int i = 0; i < q; i++) {
        cin >> l;
        int div_s = 1 << l;      // 나눠진 부분의 한 변의 길이

        // 1. 각 부분의 격자 배열 돌린다.
        func(s, div_s);

        // TEST
        // cout << i << "번 회전 ==== " << '\n';
        // for(int i = 0; i < s; i++) {
        //     for(int j = 0; j < s; j++) {
        //         cout << ice[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        // 2. 인접한 칸에 얼음이 있는 칸이 3개 이상
        //    즉, 인접한 칸에 얼음이 없는 칸이 2개 이상이면 해당 칸의 얼음 양을 하나 줄인다.
        vector<pair<int, int>> iceList;
        for(int i = 0; i < s; i++) {
            for(int j = 0; j < s; j++) {
                if(ice[i][j] == 0) continue;
                if(BFS(i, j, s)) iceList.push_back({i, j});
            }
        }

        for(auto targetIce : iceList)
            ice[targetIce.X][targetIce.Y]--;
    }
    
    // 3. 남아있는 얼음의 합을 구한다.
    int sum = 0;
    for(int i = 0; i < s; i++)
        for(int j = 0; j < s; j++)
            sum += ice[i][j];
    
    cout << sum << '\n';

    // 4. 가장 큰 덩어리가 차지하는 칸의 갯수
    ans = AREA(s);

    cout << ans << '\n';
}