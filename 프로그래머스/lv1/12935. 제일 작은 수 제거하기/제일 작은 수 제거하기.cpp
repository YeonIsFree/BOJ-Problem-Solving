#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    if(arr.size() == 1) {
        vector<int> ans = {-1};
        return ans;
    }
    auto mn_it = min_element(arr.begin(), arr.end());
    arr.erase(mn_it);
    
    return arr;
}