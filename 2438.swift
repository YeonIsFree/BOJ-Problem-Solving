import Foundation

/*
    < 2438: 별 찍기 - 1 >  작성: YeonIsFree
    C언어로 처음 백준 문제 풀이 했을 때, 이 문제를 풀었었다. 추억이 새록새록.
 */

let num = Int(readLine()!)!

for i in 1...num {
    for _ in 1...i {
        print("*", terminator: "")
    }
    print("")
}
