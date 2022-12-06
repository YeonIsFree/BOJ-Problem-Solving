
/*
 < 5622. 다이얼 >  작성: YeonIsFree
 딕셔너리에 집어넣고 풀었는데 입력하기가 상당히 귀찮았다. 다른 풀이들읇 보니 switch - case 문을 활용하거나
 알파벳에 해당하는 숫자값만 배열에 집어넣는 풀이들이 좋아보였다. 
*/

import Foundation

let dial = ["A":3,"B":3, "C":3, "D":4, "E":4, "F":4, "G":5, "H":5, "I":5, "J":6, "K":6, "L":6, "M":7, "N":7, "O":7,
            "P":8, "Q":8, "R":8, "S":8, "T":9, "U":9, "V":9, "W":10, "X":10, "Y":10, "Z":10]
let input = readLine()!
var result = 0

for char in input {
    result += dial["\(char)"] ?? 0
}

print(result)
