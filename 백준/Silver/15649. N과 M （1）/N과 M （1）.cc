#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k) { // k는 현재까지 택한 숫자 갯수
    // base condition
    if(k == m) {
        for(int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(isused[i] == false) { // 만약 아직 i 숫자를 안썼다면,
            arr[k] = i;          // 이번에 선택할 k번째 수를 i로 선택하고
            isused[i] = true;    // i를 사용했다고 표시
            func(k+1);
            isused[i] = 0;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}