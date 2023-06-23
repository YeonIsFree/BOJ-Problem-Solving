#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int cnt = 0; // 몇 번째인지
    int num = 665; // 영화 제목이 될 번호

    while(cnt < n) {
        num++;
        int target = num;
        while(target > 0) {
            if(target % 1000 == 666) {
                cnt++;
                break;
            }
            else target /= 10;
        }
    }
    
    cout << num;
    
}