#include <bits/stdc++.h>
using namespace std;

int mx_val = -1;
int mx_idx = 0;
vector<int> solution(vector<int> array) {
    vector<int> ans;

    for(int i = 0; i < array.size(); i++) {
        if(mx_val < array[i]) {
            mx_val = array[i];
            mx_idx = i;
        }
    }
    
    ans.push_back(mx_val);
    ans.push_back(mx_idx);
    
    return ans;
}