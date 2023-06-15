#include <bits/stdc++.h>
using namespace std;

int n, m, target;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> target;

    cout << (target / m) << ' ' << (target % m); 

}