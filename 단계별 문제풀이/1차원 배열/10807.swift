
/*
 < 10807: 개수 세기 >  작성: YeonIsFree
 */

import Foundation

let caseNum: Int = Int(readLine()!)!
let inputNums: [Int] = readLine()!.split(separator: " ").map{Int($0)!}
let inputNum: Int = Int(readLine()!)!

var count = 0

inputNums.forEach{if $0 == inputNum {
    count += 1}
}

print(count)

