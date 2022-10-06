import Foundation

/*
    < 11021: A+B - 7 >  작성: YeonIsFree
 */


let num: Int = Int(readLine()!)!
// While문을 사용하기 위하여 인덱스 변수 생성. 1로 초기화.
var i: Int = 1

// [반복적으로 테스트케이스를 입력받는다]
while i <= num {
    let testCase: [Int] = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
    print("Case #\(i):", testCase[0]+testCase[1])
    
    // [Swift에는 ++ 연산자가 없다]
    i += 1
}
