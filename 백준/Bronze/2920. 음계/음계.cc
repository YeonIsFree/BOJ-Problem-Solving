#include <bits/stdc++.h>
using namespace std;

int num[8];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < 8; i++) cin >> num[i];

    bool is_ascending = false;
    bool is_decending = false;

    for(int i = 0; i < 7; i++) {
        if(num[i] + 1 == num[i+1]) is_ascending = true;
        else if(num[i] - 1 == num[i+1]) is_decending = true; 
        else {
            cout << "mixed";
            return 0;
        }
    }

    if(is_ascending == true && is_decending == false) cout << "ascending";
    if(is_ascending == false && is_decending == true) cout << "descending";   
}