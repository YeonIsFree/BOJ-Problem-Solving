#include <bits/stdc++.h>
using namespace std;

vector<string> gears;
string s;
int k, num;

vector<int> dir_check(int cur, int dir) {
    vector<int> dirs(4);
    dirs[cur] = dir;

    // cur 기준 왼쪽 진행
    int idx = cur;
    while(idx > 0 && gears[idx][6] != gears[idx - 1][2]) {
        dirs[idx - 1] = -dirs[idx];
        idx--;
    }

    // cur 기준 오른쪽 진행
    idx = cur;
    while(idx < 3 && gears[idx][2] != gears[idx + 1][6]) {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    return dirs;
}

void run(vector<int> dirs) { 
    for(int i = 0; i < 4; i++) {
        // 해당 기어의 회전 방향이 -1 이면 반시계 방향 회전
        if(dirs[i] == -1) rotate(gears[i].begin(), gears[i].begin()+1, gears[i].end());
        // 해당 기어의 회전 방향이 1 이면 시계 방향회전
        else if(dirs[i] == 1) rotate(gears[i].begin(), gears[i].begin()+7, gears[i].end());
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 4; i++) {
        cin >> s;
        gears.push_back(s);
    }
    cin >> k;
    while(k--) {
        int num_tmp, dir;
        cin >> num_tmp;
        num = num_tmp - 1;
        cin >> dir;

        // 1) num 번 기어를 시작으로 각 기어들의 회전 방향을 결정한다
        auto v = dir_check(num, dir);
        
        // 2) 각 기어들을 위에서 결정된 방향으로 돌려준다. - rotate() 이용
        run(v);
    }

    // 3) 점수를 계산한다.
    int score = 0;
    for(int i = 0; i < 4; i++)
        if(gears[i][0] == '1') score += (1 << i);
        
    // 4) 출력
    cout << score;

}