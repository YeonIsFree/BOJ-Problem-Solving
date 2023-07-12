#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    int n = arr1.size();
    int m = arr1[0].size();
    
    vector<vector<int>> answer;
    
    for(int i = 0; i < n ; i++) {
        vector<int> tmp;
        for(int j = 0; j < m; j++)
            tmp.push_back(arr1[i][j] + arr2[i][j]);
        answer.push_back(tmp);
    }
            
    return answer;
}