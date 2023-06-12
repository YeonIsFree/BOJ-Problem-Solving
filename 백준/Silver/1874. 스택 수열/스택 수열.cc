#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100003];
vector<char> ans;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    stack<int> S;

    int num = 1;

    while(n--) {
        int target = 0;
        cin >> target;
        
        if(target >= num) {
            while(target >= num) {
                S.push(num++);
                ans.push_back('+');
            }
            S.pop();
            ans.push_back('-');
        }
        else if(target < num) {
            if(S.top() != target) {
                cout << "NO" << '\n';
                return 0;
            }
            else {
                S.pop();
                ans.push_back('-');
            }
        }
    }

    for(int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';

}