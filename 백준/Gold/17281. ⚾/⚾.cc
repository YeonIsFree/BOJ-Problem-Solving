#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[9];
int mx;
vector<vector<int> > innings(52);
vector<int> player_list(10);

void play_game() {
    int score = 0;
    int idx = 0;

    bool base[4];

    // 이닝 시작
    for(int i = 0; i < n; i++) {
        int out_cnt = 0;
        fill(base, base + 4, false);

        while(out_cnt < 3) {
            int result = innings[i][player_list[idx]];
            base[0] = true;

            if(result == 0)
                out_cnt++;
            else {
                for(int i = 3; i >= 0; i--) {
                    if(base[i] == false) continue;
                    if(i + result >= 4) score++;
                    else base[i + result] = true;
                    base[i] = false;
                }
            }

            idx = (idx + 1) % 9;
        }
    }
    mx = max(mx, score);
}

void make_team(int idx) {
    if(idx == 9) {
        play_game();
        return;
    }

    if(idx == 3) {
        make_team(idx + 1);
        return;
    }

    for(int i = 1; i < 9; i++) {
        if(vis[i]) continue;
        player_list[idx] = i;
        vis[i] = true;
        make_team(idx + 1);
        vis[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;
            innings[i].push_back(tmp);
        }
    }

    make_team(0);

    cout << mx;

}