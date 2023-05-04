#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n > 0) {
        arr.push_back(n % 10);
        n /= 10;
    }
    
    sort(arr.begin(), arr.end(), greater());
    for(int i : arr)
        cout << i;

}