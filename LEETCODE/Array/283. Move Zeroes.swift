
/*
 < 283. Move Zeroes >  작성: YeonIsFree
 투포인터로 풀 수 있는 문제이다. 유투브의 파이썬 코드를 참고했더니 Time Limit Access 걸렸다... Swift는 왜이렇게 느린걸까.
 idxFrom을 한칸씩 0이 아닌 수가 나올 때까지 움직인다. 숫자를 발견하면 idxTo와 swap하고 idxTo도 한칸, idxFrom도 한칸씩 같이 이동해준다.
*/

import Foundation

class Solution {
    func moveZeroes(_ nums: inout [Int]) {
        var idxTo = 0
        for idxFrom in 0..<nums.count {
            if nums[idxFrom] != 0 {
                nums.swapAt(idxFrom, idxTo)
                idxTo += 1
            } else { continue }
        }
    }
}
