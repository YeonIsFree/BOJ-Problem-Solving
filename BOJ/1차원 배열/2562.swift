import Foundation

/*
    < 2562: 최댓값 >  작성: YeonIsFree
    강의에서 분명 firstIndex를 들은 것 같은데 가물가물했다.
 */

var arr: [Int] = []
var maxNum = 0
// [입력값을 arr에 하나씩 붙이고, maxNum을 업데이트 해준다]
for i in 0...8{
    arr.append(Int(readLine()!)!)
    if arr[i] > maxNum {
        maxNum = arr[i]
    }
}

print(maxNum)
// [firstIndex는 of:에 입력된 값이 나오는 첫번째 인덱스를 의미한다. 배열에 중복된 값이 있을 경우를 고려한 듯]
print(arr.firstIndex(of: maxNum)! + 1)
