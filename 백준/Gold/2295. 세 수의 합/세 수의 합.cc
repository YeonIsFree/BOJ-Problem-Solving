#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1003];
vector<int> two;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    // 두 개씩 합한 새로운 배열 two를 채운다.
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            two.push_back(arr[i] + arr[j]);
    
    sort(two.begin(), two.end());

    // arr[i] + arr[j] = arr[k]
    for(int i = n-1; i > 0; i--) {
        for(int j = 0; j < n; j++) {
            int target = arr[i] - arr[j];
            if(binary_search(two.begin(), two.end(), target)) {
                cout << arr[i];
                return 0;
            }
        }
    }  
}