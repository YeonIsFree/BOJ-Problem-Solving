
/*
 < 746. Min Cost Climbing Stairs >  작성: YeonIsFree
 앞서 풀었던 계단 오르기 문제의 응용 버전으로, 계단을 오르는데에 필요한 비용의 개념이 추가 되었다.
 */

class Solution {
    func minCostClimbingStairs(_ cost: [Int]) -> Int {
        // [dp 배열을 생성하고 0으로 초기화 한다.]
        var dp = Array(repeating: 0, count: 1010)
        let top = cost.count
        
        // [ n번째 계단까지 올라올 때까지의 최소 비용을 dp(n)이라 하고,
        //   n번째 계단에 지불해야하는 비용을 cost(n)이라 하자.
        //   계단은 한칸 혹은 두칸을 이동할 수 있으므로, 현재 계단의 최소 비용은 한칸 전, 두칸 전 상황으로부터 구할 수 있다. ]
        for i in 2...top {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        }

        return dp[top]
    }
}
