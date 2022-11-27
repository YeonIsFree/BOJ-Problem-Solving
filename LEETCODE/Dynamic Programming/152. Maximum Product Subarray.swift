
/*
 < 152. Maximum Product Subarray >  작성: YeonIsFree
 앞서 풀었던 최대 부분 배열 합 문제와 비슷하지만 고려해야 할 사항이 늘었다.
 먼저 부호가 바뀔 수 있다는 점. 즉 이전까지 최소였던 수가 한순간에 최대로 바뀔 수 있거나 혹은 그 반대의 경우도 존재한다는 것이다.
 그리고 nums 배열에서 0을 만나면 현재 인덱스부터 다시 카운팅 시작해야한다는 점.
 하지만 이 문제는 현재 인덱스를 반드시 포함하는 부분 배열을 구하는 SubProblem으로 쪼개어 푸는 기본 개념은 변하지 않는다.
 
*/

class Solution {
    func maxProduct(_ nums: [Int]) -> Int {
        var dpMax = Array(repeating: 0, count: nums.count + 1)
        var dpMin = Array(repeating: 0, count: nums.count + 1)

        if nums.count == 1 {
            return nums[0]
        } else {
            for i in 1...nums.count - 1 {
                dpMax[0] = nums[0]
                dpMin[0] = nums[0]
                
                dpMax[i] = max(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], nums[i])
                dpMin[i] = min(dpMin[i - 1] * nums[i], dpMax[i - 1] * nums[i], nums[i])
            }
            return dpMax.max()!
        }
    }
}
