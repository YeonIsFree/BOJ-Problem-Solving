
/*
 < 704. Binary Search >  작성: YeonIsFree
가장 기본적인 이진 탐색을 구현한 코드이다. 먼저 배열의 가장 처음, 마지막 인덱스를 각각 left, right로 선언한다.
그 다음 (left + right) / 2를 pivot으로 두고, 목표 숫자와 비교해나간다.
만약 목표 숫자보다 pivot 인덱스에 들어있는 수가 작다면 left를 pivot 의 한칸 오른쪽으로 당겨오고, pivot 인덱스 수가 더 크다면 right 을 pivot의 한칸 왼쪽으로 당겨온다.
위의 작업을 반복하다가 left 인덱스가 right 인덱스보다 커질 때까지 목표 숫자를 못 찾았다면 배열에 찾고자 하는 값이 없는 것이므로 -1 을 반환하고 함수를 종료한다.
*/

import Foundation

func search(nums: [Int], target: Int) -> Int {
    var left = 0
    var right = nums.count - 1
    
    while left <= right {
        let pivot = (left + right) / 2
        if nums[pivot] == target {
            return pivot
        } else if nums[pivot] < target {
            left = pivot + 1
        } else { // target < pivot
            right = pivot - 1
        }
    }
    
    return -1
}
