import Foundation

/*
    < 10818: 최소, 최대 >  작성: YeonIsFree
    1. sorted를 이용
    2. for문을 이용
 */

// [1. sorted를 이용하면 간단하게 풀 수 있다.]

let count = Int(readLine()!)!
var numbers = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}

let newNumbers = numbers.sorted()
// [데이터 개수가 주어지므로, 배열의 마지막 값을 count - 1로 간단히 찾을 수 있다.]
print(newNumbers[0], newNumbers[count-1])


// [2. for문을 이용하여 푸는 방법]

let count = Int(readLine()!)!
var numbers = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
// [최대, 최소 변수를 설정하고 제한된 범위를 설정.]
var min = 1000000
var max = -1000000
// [최소값을 찾는다. 초기에 엄청 큰 수를 넣어두고, 작은 값이 나타나면 업데이트한다.]
for i in numbers {
    if i < min {
        min = i
    } else { continue }
}
// [최대값을 찾는다]
for i in numbers {
    if i > max {
        max = i
    } else { continue }
}

print(min, max)

