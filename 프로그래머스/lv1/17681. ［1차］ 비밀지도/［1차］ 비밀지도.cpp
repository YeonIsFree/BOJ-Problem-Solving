#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> ans;
    
    for(int i = 0; i < n; i++) {
        string tmp = "";
        int new_row = arr1[i] | arr2[i];
        for(int j = 0; j < n; j++) {
            (new_row % 2)? tmp += '#' : tmp += ' ';
            new_row /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
    return ans;
}