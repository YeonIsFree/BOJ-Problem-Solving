#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[2002];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);
    
    int cnt = 0;
    for(int k = 0; k < n; k++) {
        int st = 0, en = n-1; 
        long long target = arr[k];
        while(st < en) {
            long long sum = arr[st] + arr[en];
            if(sum < target) st++;
            else if(sum > target) en--;
            else if(sum == target) {
                if(st != k && en != k) {
                    cnt++;
                    break;
                }
                else if(st == k) st++;
                else if(en == k) en--;
            }
        }
    }

    cout << cnt;

}