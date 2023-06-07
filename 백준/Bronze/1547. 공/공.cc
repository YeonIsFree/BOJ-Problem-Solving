#include <bits/stdc++.h>
using namespace std;

int m;
int arr[4];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;

    arr[1] = 1; arr[2] = 2; arr[3] = 3;

    while(m--) {
        int a, b;
        cin >> a >> b;
        swap(arr[b], arr[a]);
    }

    for(int i = 1; i <= 3; i++)
        if(arr[i] == 1) cout << i;
}