#include <bits/stdc++.h>
using namespace std;

string x, y;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    string sum = to_string(stoi(x) + stoi(y));
    reverse(sum.begin(), sum.end());
    cout << stoi(sum);
}