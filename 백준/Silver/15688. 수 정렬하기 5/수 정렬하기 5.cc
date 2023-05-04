#include <bits/stdc++.h>
using namespace std;

int n;
int arr[1000002];
int temp[1000002];

void merge(int st, int en) {
    int mid = (st + en) / 2;
    int l_idx = st;
    int r_idx = mid;
    for(int i = st; i < en; i++) {
        if(l_idx == mid) temp[i] = arr[r_idx++];
        else if(r_idx == en) temp[i] = arr[l_idx++];
        else if(arr[l_idx] <= arr[r_idx]) temp[i] = arr[l_idx++];
        else temp[i] = arr[r_idx++];
    }
    for(int i = st; i < en; i++)
        arr[i] = temp[i];
}

void merge_sort(int st, int en) {
    if(en - st == 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    merge_sort(0, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}