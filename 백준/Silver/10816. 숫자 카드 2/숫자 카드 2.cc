#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr1[500003]; // 입력 배열 
int arr2_origin[500003]; // 원본 저장소
int arr2[500003]; // 입력 배열에 몇개 있는지 알아내야 할 숫자들
map<int, int> cnt;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
        arr2_origin[i] = arr2[i];
    }

    sort(arr2, arr2 + m);

    for(int i = 0; i < m; i++)
        cnt[arr2[i]] = 0;
    
    for(int i = 0; i < n; i++) {
        int target = arr1[i];
        if(binary_search(arr2, arr2 + m, target))
            cnt[target]++;
    }

    for(int i = 0; i < m; i++) {
        int num = arr2_origin[i];
        cout << cnt[num] << ' ';
    }
}