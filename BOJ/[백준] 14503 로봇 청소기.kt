/*
import java.io.BufferedReader
import java.io.InputStreamReader

const val BLANK = "0"
const val WALL = "1"

val dr = arrayOf(-1, 0, 1, 0)
val dc = arrayOf(0, 1, 0, -1)


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {


    val (N, M) = readLine().split(" ").map { it.toInt() }
    var (r, c, dir) = readLine().split(' ').map { it.toInt() }


    val cleaned = Array(N) { BooleanArray(M) { false } }
    var cleanedArea = 0

    val map = mutableListOf<List<String>>()
    repeat(N) { map.add(readLine().split(' ')) }

    val canClean: (Int, Int) -> Boolean = { row, col ->
        !cleaned[row][col] && map[row][col] == BLANK
    }

    while (true) {
        // 1. 현재 위치를 청소한다.
        if(!cleaned[r][c]) cleanedArea++
        cleaned[r][c] = true

        // 2. 현재 위치에서 다음을 반복하면서 인접한 칸을 탐색한다.
        var backToStepOne = false
        var justPivot = 0
        while (true) {
            dir = (dir - 1 + 4 ) % 4 // 방향 전환
            val nextRow = r + dr[dir]
            val nextCol = c + dc[dir]

            if (canClean(nextRow, nextCol)) {
                r = nextRow
                c = nextCol // 한칸 전진
                backToStepOne = true
            } else {
                justPivot++

                if (justPivot == 4) {
                    // 뒷쪽 확인
                    val backRow = r + dr[(dir + 2) % 4]
                    val backCol = c + dc[(dir + 2) % 4]

                    if (map[backRow][backCol] == WALL) {
                        print(cleanedArea)
                        return@with // 동작 멈춤
                    } else {
                        r = backRow // 후진
                        c = backCol
                        backToStepOne = true
                    }
                }
            }
            if (backToStepOne) break // step2를 벗어나서 step1 진행
        }
    }
}
*/
