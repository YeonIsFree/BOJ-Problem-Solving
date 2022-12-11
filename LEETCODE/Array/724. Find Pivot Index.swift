
/*
 < 724. Find Pivot Index >  작성: YeonIsFree
 Sliding 이라는 기법을 배웠다. 슬라이딩은 "고정된 사이즈의 윈도우가 이동"하면서 윈도우 내의 데이터를 이용하는 알고리즘을 뜻한다.
*/

import Foundation

class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        let sum = nums.reduce(0){$0 + $1}
        var leftSum = 0
        var rightSum = sum
        var pastPivotNum = 0

        for idx in 0..<nums.count {
            let pivotNum = nums[idx]
            rightSum = rightSum - pivotNum
            leftSum = leftSum + pastPivotNum

            if leftSum == rightSum {
                return idx
            }
            pastPivotNum = pivotNum
        }

        return -1
    }
}
