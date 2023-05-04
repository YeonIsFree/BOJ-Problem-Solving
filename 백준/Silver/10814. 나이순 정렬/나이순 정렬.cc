#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> arr[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int age = 0;
        string name = "";
        cin >> age >> name;
        arr[age].push_back(name);
    }

    for(int i = 0 ; i < 100000; i++) {
        if(arr[i].empty()) continue;
        for(int j = 0; j < arr[i].size(); j++)
            cout << i << ' ' << arr[i][j] << '\n';
    }
    
}