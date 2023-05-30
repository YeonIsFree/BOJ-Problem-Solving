#include <bits/stdc++.h>
using namespace std;

int n, m;

unordered_map<string, int> idx;

int deg[1003];
int deg_copy[1003];
string arr[1003];
vector<int> adj[1003];
vector<int> origin;
vector<int> children[1003];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    for(int i = 0; i < n; i++)
        idx[arr[i]] = i;
    
    cin >> m;
    while(m--) {
        string a, b;
        cin >> a >> b;
        adj[idx[b]].push_back(idx[a]);
        deg[idx[a]]++;
    }

    for(int i = 0; i < n; i++)
        deg_copy[i] = deg[i];

    for(int i = 0; i < n; i++)
        if(deg[i] == 0) origin.push_back(i);
    
    // 시조의 수와 이름을 출력
    cout << origin.size() << '\n';
    for(int i : origin) cout << arr[i] << ' ';
    cout << '\n';

    // 
    for(int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        for(int child : adj[i]) {
            if(deg[child] - deg[i] == 1) children[i].push_back(child);
        }
    }

    for(int i = 0 ; i < n; i++) {
        cout << arr[i] << ' ' << children[i].size() << ' ';
        for(int child : children[i]) cout << arr[child] << ' ';
        cout << '\n';
    }

}