
/*
 < 4344: 평균은 넘겠지 >  작성: YeonIsFree
 */

import Foundation

let caseNum = Int(readLine()!)!

for _ in 1...caseNum {
    var testCase = readLine()!.split(separator: " ").map{ Double($0)! }
    let studentNum = Double(testCase.removeFirst())
    let average = Double(testCase.reduce(0) { $0 + $1 } / studentNum)
    let ratio = String(format: "%.3f", Double(testCase.filter{ $0 > average }.count) / studentNum * 100.0 )
    
    print("\(ratio)%")
}


