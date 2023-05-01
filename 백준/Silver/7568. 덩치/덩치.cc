#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int n, x, y;
// x : weight   y : height
vector<pair<int, int> > status;
int grade[53];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        status.push_back({x, y});
    }

    for(int i = 0; i < n; i++) {
        int now_w = status[i].X;
        int now_h = status[i].Y;
        for(int j = 0; j < n; j++) {
            if(now_w > status[j].X && now_h > status[j].Y)
                grade[j] += 1;
        }
    }

    for(int i = 0; i < n; i++)
        cout << grade[i] + 1 << ' ';
}