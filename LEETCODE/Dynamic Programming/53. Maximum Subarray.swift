
/*
 < 53. Maximum Subarray >  작성: YeonIsFree
 이 문제는 정수형 배열에서 최대 부분합을 구하는 문제로, Dynamic Programming에서 유명한 문제라 한다.
 투 포인터를 이용한 Brute Force 방법으로도 풀 수 있지만 이 경우 시간복잡도가 O(n^2) 혹은 O(n^3)까지 나올 수 있기 때문에
 그다지 좋은 방법이 아니다.
 
 이 문제를 푸는 가장 정석적인 방법은 Kadane's Algorithm을 이용하는 것이다.
 F(n) = Max(Input(n), F(n-1) + Input(n))
 
*/

class Solution {
    func maxSubArray(_ nums: [Int]) -> Int {

        if nums.count == 1 { return nums[0]}

        var dp = Array(repeating: 0, count: nums.count)
        dp[0] = nums[0]

        for i in 1...nums.count - 1 {
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
        }

        return dp.max()!
    }
}
