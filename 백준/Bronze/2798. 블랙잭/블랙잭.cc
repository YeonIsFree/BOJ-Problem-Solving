#include <bits/stdc++.h>
using namespace std;

int n, m, mx;
int arr[103];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> isselected(n, 1);
    for(int i = 0; i < n - 3; i++) 
        isselected[i] = 0;
    
    do {
        // cout << "이번 조합의 인덱스는 : ";
        // for(int i = 0; i < isselected.size(); i++)
        //     cout << isselected[i] << ' ';
        // cout << '\n';

        int temp_sum = 0;
        for(int i = 0; i < isselected.size(); i++) {
            // 선택되지 않은 카드면 거른다.
            if(isselected[i] == 0) continue;
            // 선택된 카드들은 더한다.
            temp_sum += arr[i];
        }
        // 선택된 카드들을 다 더해서 M을 넘어가는 조합은 pass
        if(temp_sum > m) continue;
        mx = max(mx, temp_sum);
        
    } while(next_permutation(isselected.begin(), isselected.end()));
    cout << mx;
    // next_permutation으로 조합 3개를 만들어낸다.
    // 1로 사용된 애들을 합해서 m (목표 합) 보다 크면 pass
    // 작으면 잠깐 temp에 저장해뒀다가 mx 값 갱신해가며 찾는다.

}