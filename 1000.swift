
import Foundation

/*
    < 1000: A+B >   작성: YeonIsFree
    readLine()을 이용, 사용자 입력값을 받는 것을 연습할 수 있다.
        1. 문제 풀이용 코드
        2. if let 바인딩 연습용 코드
 */

// [1. 문제풀이용 코드]


let input = readLine()!.split(separator: " ")

let a = Int(input[0])!
let b = Int(input[1])!

print(a+b)


// [2. if let 바인딩 연습용 코드]

// [입력]
let input:String? = readLine()

// [옵셔널 체크 후 데이터를 담을 변수 선언]
var inputData: String = ""
var a: Int = 0
var b: Int = 0

// [입력값(String): 옵셔널 값을 벗기고 변수에 대입]
if let checkInput = input {
    inputData = checkInput
}
// [공백을 기준으로 문자열을 분리 : 결과값은 String 배열]
let inputArr = inputData.split(separator: " ")

// [A,B값: 옵셔널 값을 벗기고 변수에 대입]
if let checkA = Int(inputArr[0]), let checkB = Int(inputArr[1]) {
    a = checkA
    b = checkB
}

print(a+b)


