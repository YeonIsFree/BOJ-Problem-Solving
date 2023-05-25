#include <bits/stdc++.h>
using namespace std;

int n;
int lc[27];
int rc[27];

void preorder(int cur) {
    cout << char(cur + 'A' - 1);
    if(lc[cur] != 0) preorder(lc[cur]);
    if(rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
    if(lc[cur] != 0) inorder(lc[cur]);
    cout << char(cur + 'A' - 1);
    if(rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
    if(lc[cur] != 0) postorder(lc[cur]);
    if(rc[cur] != 0) postorder(rc[cur]);
    cout << char(cur + 'A' - 1);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char node, left_child, right_child;
        cin >> node >> left_child >> right_child;
        if(left_child != '.') lc[node - 'A' + 1] = left_child - 'A' + 1;
        if(right_child != '.') rc[node - 'A' + 1] = right_child - 'A' + 1;
    }

    // 전위
    preorder(1);
    cout << '\n';

    // 중위
    inorder(1);
    cout << '\n';
    
    // 후위
    postorder(1);
    cout << '\n';
}
