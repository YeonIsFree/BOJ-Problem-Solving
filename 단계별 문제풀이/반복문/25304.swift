import Foundation

/*
    < 25304: 영수증 >  작성: YeonIsFree
 */

let totalPrice = Int(readLine()!)!
let num = Int(readLine()!)!
var total = 0
var subTotal = 0

for _ in 1...num {
    let list = readLine()!.split(separator: " ").map{(value) -> Int in return Int(value)!}
    subTotal = list[0] * list[1]
    total += subTotal
}

total == totalPrice ? print("Yes") : print("No")
