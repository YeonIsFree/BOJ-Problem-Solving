#include <bits/stdc++.h>
using namespace std;

int n, m;
int input[10];
int arr[10];
bool isused[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < m; i++)
            cout << input[arr[i]] << ' ';
        cout << '\n';
        return;  
    }

    for(int i = 0; i < n; i++) {
        if(isused[i] == false) {
            arr[k] = i;
            isused[i] = true;
            func(k+1);
            isused[i] = false;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> input[i];
    sort(input, input + n);
    func(0);
}