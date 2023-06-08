#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

bool is_right(int a, int b, int c) {
    if((c*c) == (a*a + b*b)) return true;
    else return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        arr.clear();
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());

        bool ans = is_right(arr[0], arr[1], arr[2]);

        if(ans) cout << "right" << '\n';
        else cout << "wrong" << '\n';
    }
    
}