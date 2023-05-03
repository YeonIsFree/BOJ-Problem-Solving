#include <bits/stdc++.h>
using namespace std;

int n;
int arr[10003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        arr[temp]++;
    }

    for(int i = 0; i < 10001; i++) {
        for(int j = 0; j < arr[i]; j++)
            cout << i << '\n';
    }
}