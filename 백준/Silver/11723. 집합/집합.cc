#include <bits/stdc++.h>
using namespace std;

int m;
vector<bool> arr(22);

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
  
    while(m--) {
        string com = "";
        cin >> com;
        if(com == "add") {
            int x;
            cin >> x;
            if(arr[x]) continue;
            arr[x] = true;
        }
        else if(com == "remove") {
            int x;
            cin >> x;
            if(!arr[x]) continue;
            arr[x] = false;
        }
        else if(com == "check") {
            int x;
            cin >> x;
            if(arr[x]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(com == "toggle") {
            int x;
            cin >> x;
            if(arr[x]) arr[x] = false;
            else arr[x] = true;
        }
        else if(com == "all") {
            for(int i = 1; i <= 20; i++) arr[i] = true;
        }
        else if(com == "empty") {
            for(int i = 1; i <= 20; i++) arr[i] = false;
        }
    }  
}