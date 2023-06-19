#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> ans;
    for(auto com : commands) {
        vector<int> arr;

        int st = com[0] - 1, en = com[1] - 1, target_idx = com[2] - 1;
        for(int i = st; i <= en; i++) {
            arr.push_back(array[i]);
        }
        sort(arr.begin(), arr.end());
        ans.push_back(arr[target_idx]);
    }  
    return ans;
}