#include <bits/stdc++.h>
using namespace std;

int n, m;
int st, en;
int arr[100002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    // st, en 찾기 
    // st : 주어진 강의의 최대길이    en : 강의들의 총 합
    for(int i = 0; i < n; i++) {
        st = max(st, arr[i]);
        en += arr[i];
    }

    // 강의 길이의 합을 구해 나가면서 필요한 블루레이 갯수를 구한다. 
    while(st <= en) {
        int mid = (st + en) / 2;  // 이번 루프의 블루레이 크기 
        int cnt = 0;              // 필요한 블루레이 갯수
        int sum = 0;              // 강의 길이의 합
        
        // 이번 루프의 블루레이 크기를 고려한 필요 블루레이 갯수 구하기
        for(int i = 0; i < n; i++) {
            if(sum + arr[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += arr[i];  
        }
        if(sum != 0) cnt++; // 마지막으로 필요한 블루레이 추가

        // 필요한 블루레이 갯수(cnt)와 준비된 블루레이 갯수(m)을 비교
        if(cnt > m)
            st = mid + 1;
        else if(cnt <= m)
            en = mid - 1;
    }

    cout << st;

}