#include <bits/stdc++.h>
using namespace std;

int a, b;
int tmp;
int arr[4];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 4; i++) {
        cin >> a >> b;
        tmp += -a + b;
        arr[i] = tmp;
    }
    sort(arr, arr+4);
    cout << arr[3];
}