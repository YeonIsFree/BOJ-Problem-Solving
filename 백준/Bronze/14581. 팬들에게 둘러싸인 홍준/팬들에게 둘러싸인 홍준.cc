#include <bits/stdc++.h>
using namespace std;

string s;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for(int i = 0; i < 3; i++) cout << ":fan:";
    cout << '\n';
    cout << ":fan::" << s << "::fan:" << '\n';
    for(int i = 0; i < 3; i++) cout << ":fan:";

}