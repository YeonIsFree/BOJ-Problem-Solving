#include <bits/stdc++.h>
using namespace std;

int n, l;
deque<pair<int, int> > DQ;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
    
        while(DQ.size() != 0 && DQ.back().second > num)
            DQ.pop_back();
        
        DQ.push_back({i, num});

        if(DQ.front().first <= i - l) DQ.pop_front();

        cout << DQ.front().second << ' ';
    }
}