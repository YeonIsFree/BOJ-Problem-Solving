#include <bits/stdc++.h>
using namespace std;

int arr[6];

bool checker(int arr[]) {
    for(int i = 1; i <= 5; i++)
        if(arr[i] != i) return false;
    return true;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // input
    for(int i = 1; i <= 5; i++) cin >> arr[i];

    // ----
    while(!checker(arr)) {
        for(int i = 1; i < 5; i++) {
        if(arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                for(int i = 1; i < 6; i++) cout << arr[i] << ' ';
                cout << '\n';
            }
        } 
    } 
}