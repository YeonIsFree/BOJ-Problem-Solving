import Foundation

/*
    < 10951: A+B - 4 >  작성: YeonIsFree
    Swift의 옵셔널 타입. 즉, nil을 활용하기 아주 좋은 문제이다.
    xcode에서는 오류가 나지 않았지만 백준에서는 무한 루프 때문인지 런타임 에러가 났다.
 */

// [강제 unwrapping을 사용하지 않고, nil이 들어오면 while문에 진입하지 않게 만든다]
while let input = readLine() {
    let nums: [Int] = input.split(separator: " ").map{(value) -> Int in return Int(value)!}
    
    print(nums[0]+nums[1])
}
