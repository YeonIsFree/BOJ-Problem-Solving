#include <bits/stdc++.h>
using namespace std;

int n, m, st;
int arr[10];
int input[10];

void func(int k) {
    if(k == m) {
        for(int i = 0; i < k; i++) 
            cout << input[arr[i]] << ' ';
        cout << '\n';
        return;
    }

    if(k != 0)
        st = arr[k-1];

    for(int i = st; i < n; i++) {
        arr[k] = i;
        func(k+1);
    }   
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input+n);
    func(0);
}