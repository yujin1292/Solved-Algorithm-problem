import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs


val dc = arrayOf(0, 0, 1, -1)
val dr = arrayOf(1, -1, 0, 0)
var n = 0
var l = 0
var r = 0

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    readLine().split(" ").map { it.toInt() }.let {
        n = it[0]
        l = it[1]
        r = it[2]
    }

    val map = mutableListOf<Int>()

    repeat(n) {
        map.addAll(readLine().split(" ").map { it.toInt() })
    }

    var day = 0
    while (true) {
        if (!move(map)) break // 인구 이동이 없을 시
        day++
    }
    println(day)
}

// O(N^2)
fun getNationalBorder(nation: MutableList<Int>): Array<MutableSet<Int>> {
    val nationBorder = Array(n * n) {  mutableSetOf<Int>() }
    for (i in 0 until n) {
        for (j in 0 until n) {
            val current = i * n + j

            for (dir in 0 until 4) {
                val nextCol = i + dc[dir]
                val nextRow = j + dr[dir]
                if (nextCol !in 0 until n) continue
                if (nextRow !in 0 until n) continue
                val nextNation = nextCol * n + nextRow

                if (abs(nation[current] - nation[nextNation]) in l..r) {
                    // open
                    nationBorder[current].add(nextNation)
                    nationBorder[nextNation].add(current)
                }
            }
        }
    }

    return nationBorder
}


// O(N^2)
fun move(nation: MutableList<Int>): Boolean {

    val border = getNationalBorder(nation)
    var moved = false

    // bfs 를 통해 인구 움직
    val visited = BooleanArray(n * n) { false }

    for (i in 0 until n * n) {
        if (visited[i]) continue
        visited[i] = true
        // 국경이 열려있지않으면 시도도 하지않는다
        if( border[i].isEmpty()) continue

        // 연합국을 bfs 를 통해 찾음
        val q: Queue<Int> = LinkedList()
        q.offer(i)
        val area = mutableListOf(i)
        var population = nation[i]
        while (q.isNotEmpty()) {
            val front = q.poll() ?: break
            for (next in border[front]) {
                if (visited[next]) continue
                visited[next] = true

                area.add(next)
                population += nation[next]

                q.offer(next)
            }
        }

        // 인구 이동 시작 인구 차이가 0인 경우는 없으므로, 경계가 열리면 무조건 이동이 일어난다
        moved = true
        for (a in area) nation[a] = population / area.size
    }

    return moved
}
