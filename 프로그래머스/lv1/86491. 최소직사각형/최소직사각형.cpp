#include <bits/stdc++.h>
using namespace std;

int mx_w, mx_h;

int solution(vector<vector<int>> sizes) {
    int len = sizes.size();
    for(int i = 0; i < len; i++) {
        sort(sizes[i].begin(), sizes[i].end());
        mx_w = max(mx_w, sizes[i][0]);
        mx_h = max(mx_h, sizes[i][1]);
    }
    
    return mx_w * mx_h;
    
    
}