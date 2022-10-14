
/*
 < 4673: 셀프 넘버 >  작성: YeonIsFree
 먼저 다음 수를 생성하는 함수를 작성하여 나온 결과값들을 nonSelfNumArr에 저장한다. (생성이 되면 셀프넘버가 아니기 때문이다.)
 그 다음, 1부터 10,000까지 숫자로 채운 fullNumArr에서 셀프넘버가 아닌 숫자들을 빼고 남은 값들을 반환한다.
 남은 값들을 걸러내는데에 시간이 많이 걸렸는데, 어떤 블로그에서 Set 타입을 이용하는걸 보고 나도 Set의 subtracting 메서드를 이용하였다.
 */

import Foundation

// [셀프넘버가 아닌 수들과 1 ~ 10,000를 담을 빈 배열을 생성한다.]
var nonSelfNumArr: [Int] = []
var fullNumArr: [Int] = []

func genNextNum(_ num: Int) -> Int {
    // [각 자리수를 더하기 위해 숫자를 배열로 쪼갠다.]
    let numArr: [Int] = String(num).map{Int(String($0))!}
    var nextNum: Int = num
    
    for i in numArr {
        nextNum += i
    }
    
    return nextNum
}
// [위에서 생성한 빈 배열들을 채운다.]
for i in 1...10000{
    nonSelfNumArr.append(genNextNum(i))
    fullNumArr.append(i)
}
// [각 배열들을 Set 타입으로 변환하고, 셀프 넘버가 아닌 수들은 빼준다]
let selfNums = Set(fullNumArr).subtracting(Set(nonSelfNumArr))

// [Set은 순서가 없기 때문에 sorted로 정렬해주고, 차례로 프린트한다]
for i in selfNums.sorted() {
    print(i)
}
