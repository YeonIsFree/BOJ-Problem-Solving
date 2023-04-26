#include <bits/stdc++.h>
using namespace std;

int n, m;
int s;
int arr[10];
bool isused[10];

void func(int k) {
    // base condition
    if(k == m) {
        for(int i = 0; i < m; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    
    if(k == 0) 
        s = 1;
    else // (k != 0)
        s = arr[k-1] + 1;
    
    // main logic
    for(int i = s; i <= n; i++) {
        if(isused[i] == false) {
            arr[k] = i;
            isused[i] = true;
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