#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    // main logic : 비내림차순. 오름차순인데 중복 허용으로 이해하면 될까.
    int st = 0;
    if(k == 0)
        st = 1;
    else // if(k != 0)
        st = arr[k-1];
    
    for(int i = st; i <= n; i++) {
        arr[k] = i;
        func(k+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}