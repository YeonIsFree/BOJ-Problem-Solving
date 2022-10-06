import Foundation

/*
    < 10871: X보다 작은 수 >  작성: YeonIsFree
    (Oct.5.2022) 아직 클로저, 고차함수를 배우지 않아서 map을 쓰고 싶지 않았으나, 배열 입력값을 다뤄야하므로 불가피하게 쓰게됨
 */

// [ map 함수: {(기존 타입) -> 바꿀 타입 in return 바꿀 내용} ] <-- 배운 후 수정하기
let input1 = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
let input2 = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}

// [ 처음 입력값으로 받은 데이터 갯수를 배열의 인덱스 마지막 번호로 이용 (배열은 0부터 시작하기 때문) ]
let index = input1[0] - 1
let num = input1[1]

// [ Q.의문: 왜 "for i in input2" 로 구현하면 에러가 날까 ]
for i in 0...index {
    if input2[i] < num {
        print(input2[i], terminator: " ")
    }
}
