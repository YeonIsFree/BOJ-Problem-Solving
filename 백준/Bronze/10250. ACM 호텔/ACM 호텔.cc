#include <bits/stdc++.h>
using namespace std;

int t, h, w, n;
int arr[101][101];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> h >> w >> n;
        for(int i = 1; i <= h; i++)
            fill(arr[i]+1, arr[i]+w+1, 0);
        int cnt = 1, floor = 0, room = 0;
        for(int i = 1; i <= w; i++) {
            for(int j = 1; j <= h; j++) {
                arr[j][i] = cnt;
                if(cnt == n) {
                    floor = j;
                    room = i;
                }
                cnt++;
            }
        }
        cout << (floor * 100) + room << '\n';
    } // 모든 테스트 케이스 종료
}
