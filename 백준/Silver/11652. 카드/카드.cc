#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    int cnt = 0;
    int mx = 0;
    long long mxval = -(1ll << 62) - 1;
    for(int i = 0; i < n; i++) {
        // 맨 처음 원소를 보고 있거나 내 이전 값과 같으면 갯수를 세어준다.
        if(i == 0 || arr[i-1] == arr[i]) cnt++;
        else {
            if(cnt > mx) {
                mx = cnt;
                mxval = arr[i-1];
            }
            // 여기에 도달했다는 것은 이전 숫자와 현재가 다르다는 것.
            // 따라서 카운팅을 초기화 해준다.
            cnt = 1;
        }
    }
    // 제일 마지막 수를 고려하는 코드
    if(cnt > mx) mxval = arr[n-1];
    cout << mxval;
}