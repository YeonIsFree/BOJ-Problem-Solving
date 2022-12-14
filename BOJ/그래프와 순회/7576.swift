
/*
 < 7576. 토마토 >  작성: YeonIsFree
 이 문제를 풀며 더욱더 C++을 공부하고 싶어졌다. Swift는 느리다. 심지어 Swift에는 Queue 자료구조가 구현되어 있지 않다.
 깃헙에서 다른 사람이 구현해 놓은 코드를 가져왔는데, 처음 가져다 썼던 코드의 dequeue가 O(n)이라 계속 시간초과가 났었다.
 처음에는 뭐가 문제인지 몰라 한참을 백준을 뒤적거리다가 나와 비슷한 사람의 질문글을 보게 되었고, 다행히 O(1) 코드로 교체해서 통과했다.
 
 다른 사람들의 코드를 보니 Queue 자료구조를 처음부터 정의하지 않고 그냥 배열로 필요한 기능만 구현해서 쓰는 것 같다.
 하긴 코딩테스트에서는 검색이 안될 수도 있으니 그게 맞겠지... <- 아니 애초에 C++처럼 STL에 넣어주면 덧나나
 ----------------------------------------------------------------------------------------------------
 우선 주어진 m, n에 맞는 2차원 배열 grid를 생성하고 해당 배열의 값을 썩는 일수(day)로 채우는 것을 목표로 한다. grid 칸에 토마토가 없으면 -1을 채우고,
 상한 토마토가 들어있으면 1을, 멀쩡한 토마토가 들어있으면 0을 채운다. 상한 토마토에서부터 사방으로 토마토가 썩어 나가므로 상한 토마토가 들어있는 좌표를 Queue에 채우고 시작한다.
 
 이제 큐에 들어있는 좌표들을 하나씩 꺼내서(Dequeue) 그 다음날의 상황을 구현해나간다.
*/

import Foundation

public struct Queue<T> {
  fileprivate var array = [T?]()
  fileprivate var head = 0
  
  public var isEmpty: Bool {
    return count == 0
  }

  public var count: Int {
    return array.count - head
  }
  
  public mutating func enqueue(_ element: T) {
    array.append(element)
  }
  
  public mutating func dequeue() -> T? {
    guard head < array.count, let element = array[head] else { return nil }

    array[head] = nil
    head += 1

    let percentage = Double(head)/Double(array.count)
    if array.count > 50 && percentage > 0.25 {
      array.removeFirst(head)
      head = 0
    }
    
    return element
  }
  
  public var front: T? {
    if isEmpty {
      return nil
    } else {
      return array[head]
    }
  }
}
// ----------------------------------------------------------------
func tomato() {
    let line = readLine()!.split(separator: " ").map{Int($0)!}
    let m = line[0] // col
    let n = line[1] // row
    // [인덱스 값을 1부터 시작하고 싶어서 row, col를 입력값으로부터 한칸씩 더 많이 만든다. 즉, 좌표는 (1,1)부터 고려한다.]
    var grid = Array(repeating: Array(repeating: 0, count: m + 1), count: n + 1)
    
    struct Coor {
        let x: Int
        let y: Int
    }
    // [상한 토마토의 좌표를 담을 큐를 생성한다.]
    var q = Queue<Coor>()
    
    // [grid를 입력값들로 채운다. 토마토가 없는 경우 -1, 상한 토마토가 있는 경우 1, 멀쩡한 토마토가 있는 경우 0을 채워준다.]
    for row in 1...n {
        grid[row] = [0] + readLine()!.split(separator: " ").map{Int($0)!}
    }
    
    for row in 1...n {
        for col in 1...m {
            if grid[row][col] == 1 {
                q.enqueue( Coor(x: row, y: col))
            }
        }
    }
    
    while !(q.isEmpty) {
        let current = q.dequeue()!
        
        let dx = [1, -1, 0, 0]
        let dy = [0, 0, 1, -1]
        
        for i in 0...3 {
            let nextX = current.x + dx[i]
            let nextY = current.y + dy[i]
            // [다음 좌표가 범위를 벗어나면 패스]
            if !(1 <= nextX && nextX <= n && 1 <= nextY && nextY <= m) {
                continue
            }
            // [토마토가 안들어있는 칸이면 패스]
            if grid[nextX][nextY] == -1 {
                continue
            }
            // [멀쩡한 토마토가 들어있으면 전염시키고 큐에 넣어준다.]
            if grid[nextX][nextY] == 0 {
                grid[nextX][nextY] += grid[current.x][current.y] + 1
                q.enqueue( Coor(x: nextX, y: nextY))
            }
        }
        
    }
    
    var max = -98765
    var tempMax = 0
    // [멀쩡한 사과 있으면 -1을 프린트하고 함수 종료]
    for i in 1...n {
        // [처음에 그냥 contains(0)을 했을 때 무조건 -1이 나오는 오류가 있었는데,
        //  인덱스를 1부터 쓰고 싶어서 배열의 가장 처음 인덱스(0)를 0으로 채워둔 걸 깜빡해서 그랬다.
        //  따라서 가장 처음 인덱스인 0부분을 dropFirst로 버리고 contains(0)을 해준다.]
        let removeZeroArr = grid[i].dropFirst()
        if  removeZeroArr.contains(0){
            print("-1")
            return
        }
        // [가장 큰 값, 즉 일수 찾기]
        tempMax = grid[i].max()!
        if tempMax > max {
            max = tempMax
        }
    }
    // [0일 일때 상한 토마토를 1로 표기하고 시작했으니 max 일수에서 -1을 해주어야 경과한 일수를 구할 수 있다.]
    print(max - 1)
    
}

tomato()
