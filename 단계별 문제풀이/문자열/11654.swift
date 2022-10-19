
/*
 < 11654: 아스키 코드 >  작성: YeonIsFree
 아직 문자열 강의를 안들어서 모르는 것 투성이였다. swift에 Charater 타입이 있는지도 몰랐고... asciiValue 라는 함수에 Character 타입을 넣을 수 있다는 것.
 */

import Foundation

if let word = Character(readLine()!).asciiValue {
    print(word)
}

