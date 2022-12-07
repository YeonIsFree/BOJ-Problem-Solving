
/*
 < 10815. 숫자 카드 >  작성: YeonIsFree
*/

import Foundation

let cardNum = Int(readLine()!)!
let cardNums = readLine()!.split(separator: " ").map{Int($0)!}.sorted()

let inputNum = Int(readLine()!)!
let inputArr = readLine()!.split(separator: " ").map{Int($0)!}

func search(nums: [Int], target: Int) -> Int {
    var left = 0
    var right = nums.count - 1
    
    while left <= right {
        let pivot = (left + right) / 2
        if nums[pivot] == target {
            return 1
        } else if nums[pivot] < target {
            left = pivot + 1
        } else {
            right = pivot - 1
        }
    }
    return 0
}

for num in inputArr {
    print(search(nums: cardNums, target: num), terminator: " ")
}
