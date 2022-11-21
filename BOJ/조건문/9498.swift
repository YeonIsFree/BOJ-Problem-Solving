import Foundation

/*
    < 9498: 시험 성적 >  작성: YeonIsFree
    switch - case문 연습
 */

let score = Int(readLine()!)!

switch score {
case 90...100: print("A")
case 80...89: print("B")
case 70...79: print("C")
case 60...69: print("D")
default: print("F")
}
