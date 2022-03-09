import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.util.*

var n = 0
val board = mutableListOf<MutableList<Int>>()
val visited = mutableSetOf<String>()
var maxAnswer = Int.MIN_VALUE

// up down left right
val dr = listOf(-1, 1, 0, 0)
val dc = listOf(0, 0, -1, 1)

val startPoint = mutableListOf<MutableList<Pair<Int, Int>>>()

fun move(dir: Int, inputBoard: MutableList<MutableList<Int>>): MutableList<MutableList<Int>> {
    val moved = mutableListOf<MutableList<Int>>()
    inputBoard.forEach { moved.add(it.toMutableList()) }

    val merged = Array(n) { Array(n) { false } }

    for (start in startPoint[dir]) {
        var row = start.first
        var col = start.second

        for (i in 0 until n) {
            row -= dr[dir]
            col -= dc[dir]
            if (row in 0 until n && col in 0 until n) {

                // step 1 부딪히는 지점 찾기
                var nextRow = row + dr[dir]
                var nextCol = col + dc[dir]

                while (nextRow in 0 until n && nextCol in 0 until n) {
                    if (moved[nextRow][nextCol] != 0) break;
                    nextRow += dr[dir]
                    nextCol += dc[dir]
                }

                // step 2 부딪히는 지점

                // case 1  부딪힘없이 범위를 벗어난경우
                if( nextRow !in 0 until n || nextCol !in 0 until n) {
                    moved[nextRow-dr[dir]][nextCol-dc[dir]] = moved[row][col]
                    moved[row][col] = 0
                    continue
                }
                // case 2 어딘가에 부딪혀서 멈춤
                if (moved[nextRow][nextCol] == moved[row][col]) {

                    if (merged[nextRow][nextCol]) { // 이미 합쳐진 적 있으면 합치지않음
                        moved[nextRow - dr[dir]][nextCol - dc[dir]] = moved[row][col]
                        moved[row][col] = 0

                    } else { // 합쳐진적 없으니 합치기!
                        moved[nextRow][nextCol] *= 2
                        maxAnswer = max(maxAnswer, moved[nextRow][nextCol])
                        moved[row][col] = 0
                        merged[nextRow][nextCol] = true
                    }
                }
                else { // 합치지못함
                    moved[nextRow - dr[dir]][nextCol - dc[dir]].let{
                        if( it == 0){
                            moved[nextRow - dr[dir]][nextCol - dc[dir]] = moved[row][col]
                            moved[row][col] = 0
                        }
                    }
                }
            }
        }
    }

    return moved
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    n = readLine().toInt()
    repeat(4) { dir ->
        startPoint.add(mutableListOf())
        repeat(n) {
            when (dir) {
                0 -> startPoint[dir].add(Pair(0, it)) // up
                1 -> startPoint[dir].add(Pair(n - 1, it)) // down
                2 -> startPoint[dir].add(Pair(it, 0)) // left
                3 -> startPoint[dir].add(Pair(it, n - 1)) // right
            }
        }
    }

    repeat(n) {
        val line = readLine().split(' ').map { it.toInt() }.toMutableList()
        board.add(line)
        maxAnswer = max(maxAnswer, line.maxOf { it })
    }

    val q: Queue<MutableList<MutableList<Int>>> = LinkedList()
    q.offer(board)
    visited.add(board.toString())

    var count = 1

    while (q.isNotEmpty()) {
        if (count > 5) break
        val size = q.size
        repeat(size) {
            val front = q.poll()
            front?.let { b ->
                repeat(4) { dir ->
                    val moved = move(dir, b)
                    if (!visited.contains(moved.toString())) {
                        q.offer(moved)
                        visited.add(moved.toString())
                    }
                }
            }
        }
        count++
    }

    println(maxAnswer)
}