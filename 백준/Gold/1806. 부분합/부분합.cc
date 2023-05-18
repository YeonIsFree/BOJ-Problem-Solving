#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100003];
int mn_len = 0x7f7f7f7f;

// 연속된 부분 수열의 합이 S 이상이 되는 것 중, 가장 짧은 수열의 길이

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int en = 0;
    int sum = arr[0];
    for(int st = 0; st < n; st++) {
        // 부분합을 구하는 부분
        while(en < n && sum < s) {
            en++;
            if(en == n) break;
            sum += arr[en];
        }
        
        // 여기로 왔다는 것은 
        // en == n이거나 sum >= s 가 됐다는 뜻!
        if(en == n) break;

        mn_len = min(mn_len, en - st + 1);
        sum -= arr[st]; // 매번 sum을 하지말고 이번 st만 빼주고 다음턴 st를 더해줄 것.
    }

    if(mn_len == 0x7f7f7f7f) {
        cout << 0;
        return 0;
    }
    cout << mn_len;
}