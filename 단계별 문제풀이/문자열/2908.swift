
/*
 < 2908: 상수 >  작성: YeonIsFree
 */

import Foundation

let inputString = readLine()!.split(separator: " ")
let firstNum = Int(inputString[0].map{String($0)}.reversed().joined())!
let secondNum = Int(inputString[1].map{String($0)}.reversed().joined())!


print(firstNum > secondNum ? firstNum : secondNum)
