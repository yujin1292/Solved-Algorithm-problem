import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Long.max
import java.lang.StringBuilder
import java.util.*

fun solve(n: Int, w: Int, graph: Array<MutableList<Int>>, inDegree: Array<Int>, times: List<Long>): Long {

    val q: Queue<Int> = LinkedList()
    val result = Array(n) { 0L }

    for (i in 0 until n) {
        if (inDegree[i] == 0) {
            q.offer(i)
            result[i] = times[i]
        }
    }

    while (q.isNotEmpty()) {
        val front = q.poll()

        for (next in graph[front]) {
            inDegree[next]--
            result[next] = max(result[next], result[front] + times[next])
            if (inDegree[next] == 0) q.offer(next)
        }
    }

    // 답 출력
    return result[w]
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val sb = StringBuilder()

    repeat(readLine().toInt()) {
        val (n, k) = readLine().split(' ').map { it.toInt() }
        val times = readLine().split(' ').map { it.toLong() }

        val inDegree = Array(n) { 0 }
        val graph = Array<MutableList<Int>>(n) { mutableListOf() }

        repeat(k) { // 규칙
            val (x, y) = readLine().split(' ').map { it.toInt() - 1 }
            graph[x].add(y)
            inDegree[y]++
        }

        val w = readLine().toInt() - 1
        sb.append("${solve(n, w, graph, inDegree, times)}\n")
    }

    println(sb.toString())
}