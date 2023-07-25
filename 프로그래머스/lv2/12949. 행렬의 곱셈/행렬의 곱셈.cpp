#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int row = arr1.size();
    int col = arr1[0].size();
    int row_2 = arr2[0].size();
    
    vector<vector<int>> answer;
    
    for(int i = 0; i < row; i++) {
        vector<int> tmp;
        for(int k = 0; k < row_2; k++) {
            int sum = 0;
            for(int j = 0; j < col; j++) {
                sum += arr1[i][j] * arr2[j][k];
            }
            tmp.push_back(sum);
        }
        answer.push_back(tmp);
    }
    return answer;
}