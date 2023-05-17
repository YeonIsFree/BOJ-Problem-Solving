#include <bits/stdc++.h>
using namespace std;

int n, m;
int st, en, mid;
int arr1[100003];
int arr2[100003];

int bst(int target) {
    // 초기 인덱스
    st = 0;
    en = n-1;

    while(st <= en) {
        mid = (st + en) / 2;

        // target이 mid와 같다면 (찾았다!)
        if(target == arr1[mid])
            return 1;

        // target이 mid보다 크다면 (오른쪽에 있음)
        else if(target > arr1[mid])
            st = mid + 1;

        // target이 mid보다 작다면 (왼쪽)
        else if(target < arr1[mid])
            en = mid - 1;   

    } // while문 종료까지 이 함수가 종료되지 않았다는 것은 target이 없다는 뜻
    return 0;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr1[i];
    sort(arr1, arr1 + n);

    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> arr2[i];

    for(int i = 0; i < m; i++)
        cout << bst(arr2[i]) << '\n';
    
}