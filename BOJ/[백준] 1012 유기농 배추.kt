import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val testCase = readLine().toInt()

    repeat(testCase) {

        val (m, n, k) = readLine().split(' ').map { it.toInt() }

        val map = Array(n) { IntArray(m) { 0 } }
        val visited = Array(n) { BooleanArray(m) { false } }
        repeat(k) {
            val (col, row) = readLine().split(' ').map { it.toInt() }
            map[row][col] = 1
        }

        var answer = 0
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (map[i][j] == 0) continue
                if (visited[i][j]) continue

                answer++
                bfs(i, j, visited, map, n, m)
            }
        }
        println(answer)
    }
}


fun bfs(row: Int, col: Int, visited: Array<BooleanArray>, map: Array<IntArray>, n: Int, m: Int) {

    val dc = arrayOf(0, 0, 1, -1)
    val dr = arrayOf(1, -1, 0, 0)

    val queue: Queue<Pair<Int, Int>> = LinkedList()

    queue.offer(Pair(row, col))
    visited[row][col] = true

    while (queue.isNotEmpty()) {
        val front = queue.poll() ?: break

        for (dir in 0 until 4) {
            val nextRow = front.first + dr[dir]
            val nextCol = front.second + dc[dir]

            if (nextRow !in 0 until n || nextCol !in 0 until m) continue
            if (visited[nextRow][nextCol]) continue
            if( map[nextRow][nextCol] == 0) continue

            visited[nextRow][nextCol] = true
            queue.offer(Pair(nextRow, nextCol))
        }
    }
}