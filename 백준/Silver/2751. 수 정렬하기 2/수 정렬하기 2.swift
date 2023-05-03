import Foundation

let n = Int(readLine()!)!
var nums: [Int] = []

for _ in 1...n {
    nums.append(Int(readLine()!)!)
}

for num in nums.sorted() {
    print(num)
}