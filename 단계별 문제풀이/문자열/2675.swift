
/*
 < 2675: 문자열 반복 >  작성: YeonIsFree
 */

import Foundation

let caseNum: Int = Int(readLine()!)!

for _ in 1...caseNum {
    let input = readLine()!.split(separator: " ")
    let repeatNum: Int = Int(input[0])!
    let inputString: [String] = String(input[1]).map{String($0)}
    
    for i in inputString {
        for _ in 1...repeatNum {
            print(i, terminator: "")
        }
    }
    print("")
}
