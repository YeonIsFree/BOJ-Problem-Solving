#include <bits/stdc++.h>
using namespace std;

int arr[5];
int sum;

int pow(int n) {
    return n * n;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 5; i++)
        cin >> arr[i];
    for(int i = 0; i < 5; i++) {
        sum += pow(arr[i]);
    }

    cout << sum % 10;
    
}