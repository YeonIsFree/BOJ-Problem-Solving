#include <bits/stdc++.h>
using namespace std;

long long n;
string input;
vector<long long> temp;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> input;
        reverse(input.begin(), input.end());
        temp.push_back(stoll(input));
    } 

    sort(temp.begin(), temp.end());

    for(long long i : temp)
        cout << i << '\n';

}