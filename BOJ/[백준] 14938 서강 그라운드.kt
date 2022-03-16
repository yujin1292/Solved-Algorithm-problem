import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*


data class Info(
    var to: Int,
    var weight: Int
) : Comparable<Info> {
    override fun compareTo(other: Info): Int = compareValuesBy(this, other) { it.weight }
}

const val INF = 100_001

var answer = 0

fun dijkstra(start: Int, m: Int, n: Int, adj: Array<MutableList<Info>>, item: MutableList<Int>) {
    val dist = Array(n + 1) { INF }

    val pq: PriorityQueue<Info> = PriorityQueue()
    pq.offer(Info(start, 0))
    dist[start] = 0

    while (pq.isNotEmpty()) {
        val cur = pq.poll()
        if (cur.weight > dist[cur.to]) continue
        for (next in adj[cur.to]) {
            if (dist[cur.to] + next.weight < dist[next.to]) {
                dist[next.to] = dist[cur.to] + next.weight
                pq.offer(Info(next.to, dist[next.to]))
            }
        }
    }
    var gets = 0
    for (i in 1..n) {
        if (dist[i] <= m) gets += item[i]
    }

    if (answer < gets) answer = gets
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (n, m, r) = readLine().split(' ').map { it.toInt() }

    val item = mutableListOf(0)
    item.addAll(readLine().split(' ').map { it.toInt() })
    val adj = Array(n + 1) { mutableListOf<Info>() }

    repeat(r) {
        val (a, b, l) = readLine().split(' ').map { it.toInt() }

        adj[a].add(Info(b, l))
        adj[b].add(Info(a, l))
    }

    for (i in 1..n) {
        dijkstra(i, m, n, adj, item)
    }
    print(answer)
}