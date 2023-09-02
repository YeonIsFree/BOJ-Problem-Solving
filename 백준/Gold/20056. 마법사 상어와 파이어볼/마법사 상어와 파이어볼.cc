#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int n, m, k;
int a, b, c, d, e;
struct Info {
    int mass;
    int speed;
    int dir;
};
vector<Info> board[52][52];

// -------

int massSum() {
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(board[i][j].size() == 0) continue;
            for(Info fireball : board[i][j])
                ret += fireball.mass;
        }
    }
    return ret;
}

bool isAllsameDir(vector<bool> dirList) {
    int len = dirList.size();
    bool target = dirList[0];
    for(bool dir : dirList) 
        if(dir != target) return false;
    return true;
}

void divider(int x, int y, vector<Info> fireballs) {
    int cnt = fireballs.size();
    int mass_sum = 0;
    int speed_sum = 0;
    vector<bool> dirList;

    for(Info fireball : fireballs) {
        mass_sum += fireball.mass;
        speed_sum += fireball.speed;
        bool isDirEven = (fireball.dir % 2 == 0) ? true : false;
        dirList.push_back(isDirEven);
    }

    int new_mass = mass_sum / 5;
    if(new_mass == 0) {
        board[x][y].clear();
        return;
    }
    int new_speed = speed_sum / cnt;

    board[x][y].clear();
    if(isAllsameDir(dirList)) {
        board[x][y].push_back({new_mass, new_speed, 0});
        board[x][y].push_back({new_mass, new_speed, 2});
        board[x][y].push_back({new_mass, new_speed, 4});
        board[x][y].push_back({new_mass, new_speed, 6});
    } 
    else {
        board[x][y].push_back({new_mass, new_speed, 1});
        board[x][y].push_back({new_mass, new_speed, 3});
        board[x][y].push_back({new_mass, new_speed, 5});
        board[x][y].push_back({new_mass, new_speed, 7});
    }
}

void  move() {
    vector<Info> tmp[52][52];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(board[i][j].size() == 0) continue;
            vector<Info> fireballs = board[i][j];

            for(Info fireball : fireballs) {
                int nx = (i + dx[fireball.dir] * fireball.speed) % n;
                int ny = (j + dy[fireball.dir] * fireball.speed) % n;

                if(nx <= 0) nx += n;
                if(ny <= 0) ny += n;

                tmp[nx][ny].push_back(fireball);
            }

            board[i][j].clear();
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            board[i][j] = tmp[i][j];
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // ---- input 
    cin >> n >> m >> k;
    while(m--) {
        cin >> a >> b >> c >> d >> e;
        Info fireball = {c, d, e};
        board[a][b].push_back(fireball);
    }

    // ---- FIREBALL 🔥
    while(k--) {
        move(); 

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(board[i][j].size() < 2) continue;
                divider(i, j, board[i][j]);
            }
        }
    }

    // ---- output
    int ans = massSum();
    cout << ans;
}