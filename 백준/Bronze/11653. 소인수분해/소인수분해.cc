#include <bits/stdc++.h>
using namespace std;

int n, tmp;
vector<int> ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        // 안나눠떨어지면 i 하나 증가시키러 다음 턴으로
        if(n % i != 0) continue;
        // 나눠떨어진다면 그때의 if를 ans 배열에 추가하고
        // n 을 나눈 몫으로 갱신한다. 
        // 그 다음 다시 똑같은 i로 n을 나눈다.
        while(n % i == 0) {
            ans.push_back(i);
            n /= i;
        }
    }

    for(int i : ans)
        cout << i << ' ';
}