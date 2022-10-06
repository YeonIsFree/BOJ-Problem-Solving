import Foundation

/*
    < 10950: A+B-3 >  작성: YeonIsFree
 */

let caseCount = Int(readLine()!)!
var i = 0

while i < caseCount {
    
    let numArray = readLine()!.split(separator: " ")

    let a = Int(numArray[0])!
    let b = Int(numArray[1])!
    
    print(a + b)
    
    i += 1
}
