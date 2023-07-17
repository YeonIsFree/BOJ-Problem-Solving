#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int sum = 0;
    int cnt = 0;
    
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++) {
        sum += d[i];
        if(sum > budget) break;
        cnt++;
    }
    return cnt;
    
    
}