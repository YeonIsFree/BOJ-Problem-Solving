#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z;
    cin >> x >> y >> z;

    int d, e, f;
    d = min({x, y, z});
    f = max({x, y, z});
    e = (x + y + z) - d - f;

    cout << d << ' ' << e << ' ' << f;
}