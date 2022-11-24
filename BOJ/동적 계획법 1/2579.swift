
/*
 < 2579. 계단 오르기 >  작성: YeonIsFree
 Bottom-up 방식의 점화식은 dp[현재 계단] = max( 2계단 전에서 올라오는 dp, 1계단 전에서 올라오는 dp ) + 현재 계단의 cost 이다.
 이 문제의 핵심은 1계단 전에서 올라오는 dp를 구할 때, '연속된 세 개의 계단을 모두 밟아서는 안된다.'를 전제로 해야 한다는 것이다.
 한칸씩 연속으로 세칸을 밟을 수 없으므로 세칸 전 상황에서 반드시 2칸을 뛰어넘는, 즉 dp[i - 3] + cost[i - 1] 상황으로 만들어 주어야 한다.
*/

import Foundation

//[입력 받기]
let steps = Int(readLine()!)!
var cost = Array(repeating: 0, count: steps + 1)
for i in 1...steps{ cost[i] = Int(readLine()!)! }
var dp = Array(repeating: 0, count: steps + 1)

//[계단이 한개, 두개일 때는 단순히 모든 비용을 더해주는 것이 최대값이되므로, reduce로 처리한다.]
if steps <= 2 {
    print(cost.reduce(0){$0 + $1})
}else {
    //[계단이 세개 이상일 때는 점화식을 이용한다.]
    for i in 3...steps {
        dp[1] = cost[1]
        dp[2] = cost[1] + cost[2]
        dp[i] = max(dp[i - 2], dp[i - 3] + cost[i - 1]) + cost[i]
    }
    print(dp[steps])
}
