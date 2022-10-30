
/*
 < 5597: 과제 안 내신 분..? >  작성: YeonIsFree
 */

import Foundation

var studentList: [Int] = []

for _ in 1...28 {
    let studentID: Int = Int(readLine()!)!
    studentList.append(studentID)
}

for i in 1...30 {
    if studentList.contains(i) {
        continue
    }else {
        print(i)
    }
}

