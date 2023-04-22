#include <bits/stdc++.h>
using namespace std;

string str;
int val;
int result;
int sign = 1;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for(char c : str) {
    // 부호를 만난 경우
    if(c == '-' || c == '+') {
      // - 를 만나기 전까지는 그냥 단순히 더해주면 된다. sign = 1인 상태
      result += val * sign;
      // - 를 만났다면 이 다음부터는 모든 수를 -로 바꿔서 합해줘야한다.
      if(c == '-') sign = -1;
      val = 0;
    } else {
      // 숫자를 만난 경우
      val *= 10;
      val += c - '0';
    }
  }
  result = result + val * sign;
  cout << result;
  
}