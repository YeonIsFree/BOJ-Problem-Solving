
/*
 < 1546: 평균 >  작성: YeonIsFree
 클로저 문법을 공부한 뒤라 일부러 연습삼아 고차함수를 왕창 써보았다.
 그동안 찜찜한 마음으로 map 함수를 썼었는데, 마음이 한결 편안해졌다.
 */

import Foundation

let subjects = Double(readLine()!)!
let grades = readLine()!.split(separator: " ").map{ Double($0)! }

// [reduce: 초기값을 0으로 세팅하고 삼항연산자를 통해 다음 수($1)와 비교한 뒤 그 중 큰 쪽을 선택한다. ]
let gradeMax = grades.reduce(0) { $0 < $1 ? $1 : $0 }
// [ 조작된 성적으로 배열을 mapping 해준다 ]
let newGrades: [Double] = grades.map{ $0 / gradeMax * 100}
// [ 조작된 성적으로 새 평균을 구한다. 점수의 총 합을 구할 때도 reduce를 이용 ]
let newAverage: Double = newGrades.reduce(0) { $0 + $1 } / subjects

print(newAverage)
