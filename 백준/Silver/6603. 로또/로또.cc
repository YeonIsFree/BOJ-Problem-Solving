#include <bits/stdc++.h>
using namespace std;

int t;
int input[52];
int arr[6];
bool isused[52];

// {1, 2, 3, 4, 5, 6, 7}

void func(int k, int st) {
    if(k == 6) {
        for(int i = 0; i < 6; i++) 
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for(int i = st; i < t; i++) {
        arr[k] = input[i];
        func(k+1, i+1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        cin >> t;
        if(t == 0) break;
        for(int i = 0; i < t; i++)
            cin >> input[i];
        // 서로 다른 숫자
        // 중복 안됨
        // 오름차순 
        func(0, 0);
        cout << '\n';
    }
}