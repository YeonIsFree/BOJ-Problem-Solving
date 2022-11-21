import Foundation

/*
    < 3052: 나머지 >  작성: YeonIsFree
    Set은 중복된 데이터를 가지지 않는다는 아이디어로 접근하였다.
 */

var result: [Int] = []

// [ 빈 배열을 생성하고, 입력값을 하나씩 붙여준다.]
for _ in 0...9 {
    let num = Int(readLine()!)!
    result.append(num % 42)
}
// [배열을 집합(Set)으로 바꿔버리면 중복 된 원소가 자동으로 제거된다. 순서에 상관없이 갯수만 세면 되므로, count를 이용한다]
print(Set(result).count)
