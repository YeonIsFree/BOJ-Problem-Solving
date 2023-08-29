#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
// 상하좌우 + 대각선 방향 벡터
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
// 대각선 방향 벡터
int dx2[4] = {-1, -1, 1, 1};
int dy2[4] = {-1, 1, 1, -1};

int n, m;
int dir, s;
int W[52][52]; // 물의 양을 표시할 배열

void TEST() {
     for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << W[i][j] << ' ';
            }
            cout << '\n';
        }
}

bool isInPrevClouds(int x, int y, vector<pair<int, int>> clouds) {
    pair<int, int> target = {x, y};
    for(auto cloud : clouds)
        if(target == cloud) return true;
    return false;
}

void copybugMagic(vector<pair<int, int>> rained) {
    for(auto coor : rained) {
        // 1) 해당 칸의 대각선을 체크해서 물이 있는 바구니 수를 세준다.
        int cnt = 0;
        for(int dir = 0; dir < 4; dir++) {
            int nx = coor.X + dx2[dir];
            int ny = coor.Y + dy2[dir];
            if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
            if(W[nx][ny] == 0) continue;
            cnt++;
        }

        // 2) 위에서 구한 바구니 수만큼 해당 칸의 물 양을 증가시킨다.
        W[coor.X][coor.Y] += cnt;
    }
}

// 구름을 이동시키고 이동한 칸의 물의 양을 증가시키는 함수
vector<pair<int, int>> move(int dir, int s, vector<pair<int, int> > clouds) {
    vector<pair<int, int> > ret;
    for(auto cloud : clouds) {
        // 1) 비 구름을 이동시킨다.
        int nx = (cloud.X + dx[dir] * s) % n;
        int ny = (cloud.Y + dy[dir] * s) % n;

        if(nx <= 0) nx += n;
        if(ny <= 0) ny += n;

        // 2) 해당 칸에 비 내리기
        W[nx][ny]++;

        // 3) 물이 증가한 칸은 따로 보관
        ret.push_back({nx, ny});
    }
    return ret;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // input
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> W[i][j];
        }
    }
    
    vector<pair<int, int>> clouds;

    clouds.push_back({n, 1});
    clouds.push_back({n, 2});
    clouds.push_back({n-1, 1});
    clouds.push_back({n-1, 2});
    
    // ------
    while(m--) {
        cin >> dir >> s;

        // 1. 모든 구름을 dir 방향으로 s칸 이동하고 해당 칸에 비를 내려준다.
        //    move 함수는 비가 내려서 물이 증가한 칸의 좌표들을 반환한다.
        vector<pair<int, int>> rained = move(dir, s, clouds);
        
        // 2. 물복사버그 마법을 시전한다.
        copybugMagic(rained);

        // 3. 물의 양이 2 이상인 모든 칸에 구름 생성
        //    이번에 새로 생길 구름의 좌표들은 따로 저장해둔다.
        vector<pair<int, int>> newClouds;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                // 3-2) 아까까지 구름이 있었던 칸은 넘어간다.
                if(isInPrevClouds(i, j, rained)) continue;

                // 3-1) 물의 양이 2 미만인 칸은 넘어간다.
                if(W[i][j] < 2) continue;
                
                // 3-3) 해당 칸에 구름을 만들고 물의 양을 2 줄인다.
                W[i][j] -= 2;
                newClouds.push_back({i, j}); 
            }
        }

        // 4. 기존 구름을 3번에서 구한 새로운 구름들로 초기화 시켜 준다.
        clouds.clear();
        for(auto newCloud : newClouds) clouds.push_back(newCloud);
    } 

    // 5. 이동이 끝난 후 물의 양의 합
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(W[i][j] == 0) continue;
            ans += W[i][j];
        }
    }

    cout << ans;

}