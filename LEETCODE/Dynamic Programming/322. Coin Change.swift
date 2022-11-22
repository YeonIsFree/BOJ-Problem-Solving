
/*
 < 322. Coin Change >  작성: YeonIsFree
 주어진 coin 배열에서 첫번째 코인으로 값을 채운다. 그 다음 코인을 이용해서 루프를 돌 때, 현재 배열에 저장된 값보다 더 작으면 값을 교체해준다.
*/

class Solution {
    func coinChange(_ coins: [Int], _ amount: Int) -> Int {
        
        var dp = Array(repeating: 999999, count: amount + 1)
        dp[0] = 0

        for coin in coins {
            for i in 0...amount {
                if i - coin >= 0 {
                    dp[i] = min(dp[i], dp[i - coin] + 1)
                }
            }
        }
        
        return dp[amount] == 999999 ? -1 : dp[amount]

    }
}
