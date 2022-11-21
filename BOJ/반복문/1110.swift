import Foundation

/*
    < 1110: 더하기 사이클 >  작성: YeonIsFree
    함수 문법을 공부하고 있었기 때문에 일부러 함수로 코드를 작성함. (와일드카드패턴을 연습할 수 있었다.)
    재미있는 문제였다!
 */

let inputNum = Int(readLine()!)!
// [가장 처음 입력값은 보존해야하므로 변수를 따로 만들어 저장한다]
var num = inputNum
// [사이클 횟수를 기록하기 위한 변수]
var count = 0

// [다음 숫자를 만들어주는 함수]
func makeNextNum(_ number: Int) -> Int {
    // [먼저 입력값의 십의 자리, 일의 자리 숫자를 분리해준다.]
    let tenthDigit = number / 10
    let unitsDigit = number % 10
    // [각 자리 수의 합]
    let digitSum = tenthDigit + unitsDigit
    
    // [각 자리 수의 합이 10이 넘어가면 일의 자리 숫자만 사용하여 다음 수를 만든다.]
    var nextNum = 0
    if digitSum >= 10 {
        nextNum = (unitsDigit * 10) + (digitSum % 10)
    } else {
        nextNum = (unitsDigit * 10) + digitSum
    }
    
    return nextNum
}

while true {
    count += 1
    num = makeNextNum(num)
    // [기존 입력값과 새로 만든 수가 같으면 사이클 횟수를 print 하고 루프 탈출]
    if num == inputNum {
        print(count)
        break
    }
}
