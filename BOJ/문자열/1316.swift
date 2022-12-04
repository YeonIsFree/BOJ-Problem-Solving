
/*
 < 1316. 그룹 단어 체커  >  작성: YeonIsFree
아래 블로그의 아이디어에 착안하여 코드를 작성하였다.
입력으로 들어오는 문자열을 한글자씩 검사하여 checkArr에 들어있는지 확인한다.
없다면 넣어주고, 만약 이미 들어있다면 배열 마지막 값이랑 같은지 비교한다. 이 부분이 연속하지 않는 경우를 걸러주는 역할을 한다.
현재 검사한 글자가 checkArr 배열의 마지막과 같지 않은 경우, 즉 그룹단어가 아닌 경우 다음 케이스 검사를 위해 checkArr를 비워주고 break 한다.
마지막으로 배열의 길이가 0이 아니라면 그룹 숫자라는 의미이므로 count에 1을 더하여 준다.
 
 참고 : https://duwjdtn11.tistory.com/584
 */

import Foundation

let num = Int(readLine()!)!
var count = 0
for _ in 1...num {
    var checkArr: [Character] = []
    let stringArr = Array(readLine()!)
    
    for i in stringArr {
        if !checkArr.contains(i) {
            checkArr.append(i)
        } else if checkArr.last != i {
            checkArr.removeAll()
            break
        }
        
    }
    
    count += (checkArr.count != 0 ? 1 : 0)
}

print(count)
