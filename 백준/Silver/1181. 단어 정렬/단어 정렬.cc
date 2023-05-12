#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<string> arr;

bool cmp(string& a, string& b) {
    // [1] 문자열 길이가 짧은 순
    int len_a = a.size(), len_b = b.size();
    if(len_a != len_b) return len_a < len_b;
    // [2] 길이 같다면 사전 순
    return a < b;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        arr.push_back(s);
    }

    sort(arr.begin(), arr.end(), cmp);
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] <<'\n';
}