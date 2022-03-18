import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

var answer = -1

data class Item(
    var board: MutableList<String>,
    var x: Int,
    var y: Int,
    var count: List<Int>
)

// (x,y)를 왼쪽상단 지점으로 size 만큼 붙인다!
fun putPaper(board: MutableList<String>, x: Int, y: Int, size: Int, paperCount: Char): MutableList<String>? {
    val after = board.toMutableList()

    for (dx in 0 until size) {
        for (dy in 0 until size) {
            val nextRow = x + dx
            val nextCol = y + dy
            if( nextCol !in 0 until 10) return null
            if( nextRow !in 0 until 10) return null

            val nextPosition = nextRow * 10 + nextCol
            if (board[nextPosition] != "1") return null
            after[nextPosition] = paperCount.toString()
        }
    }
    return after
}

// 다음에 붙일 위치 가져오기
fun getAttachablePosition(it: MutableList<String>): IntArray {
    for (i in 0 until 10) {
        for (j in 0 until 10) {
            if (it[(i * 10) + j] == "1") {
                return intArrayOf(i, j)
            }
        }
    }
    return intArrayOf(-1, -1)
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val board = mutableListOf<String>()
    repeat(10) {
        val line = readLine().split(' ')
        board.addAll(line)
    }

    // 첫번째로 붙일 위치 지정 및 queue 에 넣기
    val (x, y) = getAttachablePosition(board)
    val q: Queue<Item> = LinkedList()
    q.offer(Item(board, x, y, listOf(0, 0, 0, 0, 0)))

    // 처음부터 붙일 자리가없으니 0 출력
    if (x == -1 && y == -1) {
        println(0)
        return
    }

    // 디버깅 하기 쉬우려고 색종이에 이름을 붙인것임~
    var paperCount = 'a'
    while (q.isNotEmpty()) {
        val qSize = q.size
        paperCount++
        for (i in 0 until qSize) { // depth (붙인 종이 수 ) 를 기준으로 잘라서 계산
            val front = q.poll() ?: break
            for (size in 1..5) { // 붙일 종이의 사이즈
                if (front.count[size - 1] >= 5) continue // 이미 다 쓴경우

                val newCount = front.count.toMutableList()
                newCount[size - 1]++

                // x,y 위치에 size 크기의 색종이를 붙였다
                val attached = putPaper(front.board, front.x, front.y, size, paperCount) ?: continue

                val (nextX, nextY) = getAttachablePosition(attached)
                if (nextX == -1 && nextY == -1) { // 더이상 붙일 수가없음
                    answer = newCount.sum()
                    q.clear()
                    break
                } else {
                    q.offer(Item(attached, nextX, nextY, newCount))
                }
            }
        }
        if (answer != -1) break
    }

    println(answer)
}