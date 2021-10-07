import java.util.*

var N = 0
var M = 0

const val INF = 987654321

fun dijkstra(start: Int, g: MutableList<MutableList<Int>>): MutableList<Int> {
    var result = g[start]

    val visit = Array(result.size) { false }
    visit[start] = true

    val getNextVertex = {
        var min = Int.MAX_VALUE
        var index = -1
        for (idx in result.indices) {
            if (visit[idx]) continue
            if (min > result[idx]) {
                index = idx
                min = result[idx]
            }
        }
        index
    }

    for (i in result.indices) {
        val next = getNextVertex()
        if( next == -1 ) break // 더이상 체크할게 없음

        visit[next] = true

        for (j in result.indices) {
            if (visit[j]) continue
            result[j] = Integer.min(result[next] + g[next][j], result[j])
        }
    }
    return result
}

fun main() = with(Scanner(System.`in`)) {

    N = nextInt()
    M = nextInt()

    var g = MutableList<MutableList<Int>>(N+1) { MutableList<Int>(N+1) { INF } }

    for (i in 1..M) {
        val a = nextInt()
        val b = nextInt()
        val cost = nextInt()
        if( g[a][b] > cost ) g[a][b] = cost
    }

    for (i in 0 until N) g[i][i] = 0

    val src = nextInt()
    val dest = nextInt()


    val result = dijkstra(src, g)

    println(result[dest])

}

