import Foundation

/*
    < 1330: 두 수 비교하기 >  작성: YeonIsFree
 */

let input = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}

if input[0] > input[1] {
    print(">")
} else if input[0] < input[1] {
    print("<")
} else {
    print("==")
}
