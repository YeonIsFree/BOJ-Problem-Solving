#include <bits/stdc++.h>
using namespace std;

int burger[3];
int soda[2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> burger[0] >> burger[1] >> burger[2];
    cin >> soda[0] >> soda[1];

    sort(burger, burger + 3);
    sort(soda, soda + 2);

    cout << burger[0] + soda[0] - 50;
}