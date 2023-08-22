#include <bits/stdc++.h>
using namespace std;

int arr[21];
int st, en;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 20; i++) arr[i] = i;
    int t = 10;
    while(t--) {
        cin >> st >> en;
        vector<int> tmp;
        for(int i = st; i <= en; i++)
            tmp.push_back(arr[i]);
        
        reverse(tmp.begin(), tmp.end());

        int idx = 0;
        for(int i = st; i <= en; i++) {
            arr[i] = tmp[idx++];
        }
    }

    for(int i = 1; i <= 20; i++) cout << arr[i] << ' ';
    
}