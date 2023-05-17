#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000003];
vector<int> arr_origin;
vector<int> new_arr;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr_origin.push_back(arr[i]);
    }

    // 먼저 정렬
    sort(arr, arr+n);

    // 중복 제거
    new_arr.push_back(arr[0]); // 일단 맨 앞 하나는 무조건 넣고
    for(int i = 1; i < n; i++) { // 그 다음부턴 이전 값과 같은거 빼고 다 담는다.
        if(arr[i] == arr[i-1]) continue;
        new_arr.push_back(arr[i]);
    }

    // arr_origin = { 2, 4, -10, 4, -9 }

    // 이분탐색 - 정렬되어 있는 배열에서 target의 idx 번호 자체가 target 보다 작은 원소들의 갯수
    for(int target : arr_origin)
        cout << lower_bound(new_arr.begin(), new_arr.end(), target) - new_arr.begin() << ' ';

}
