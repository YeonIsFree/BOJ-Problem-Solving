#include <bits/stdc++.h>

using namespace std;

long long solution(long long n) {
    vector<char> ans;
    string str = to_string(n);
    sort(str.begin(), str.end(), greater());
    return stoll(str);
}