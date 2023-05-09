#include <bits/stdc++.h>
using namespace std;

int st, ed;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> st >> ed;

    vector<int> arr;

    for(int i = 1; i <= ed; i++) {
        for(int j = 0; j < i; j++)
            arr.push_back(i);
    }

    int sum = 0;
    for(int i = st-1; i < ed; i++)
        sum += arr[i];
    cout << sum;

}