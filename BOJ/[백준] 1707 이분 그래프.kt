import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

const val A = 1
const val B = -1
const val NOT_YET = 0

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val answer = StringBuilder()

    val testcase = readLine().toInt()
    repeat(testcase) {
        val (v, e) = readLine().split(' ').map { it.toInt() }
        val graph = Array(v + 1) { mutableListOf<Int>() }
        val edge = mutableListOf<Pair<Int, Int>>()
        repeat(e) {
            val (a, b) = readLine().split(' ').map { it.toInt() }
            graph[a].add(b)
            graph[b].add(a)
            edge.add(Pair(a, b))
        }

        if (isBipartiteGraph(v, graph, edge)) answer.append("YES\n")
        else answer.append("NO\n")
    }
    print(answer.toString())
}

fun isBipartiteGraph(v: Int, graph: Array<MutableList<Int>>, edge: MutableList<Pair<Int, Int>>): Boolean {
    val group = MutableList(v + 1) { NOT_YET }

    // graph 를 dfs 방식으로 순회하며 group 지정
    // 모두 연결되어있다는 보장이 없으므로 1 ~ v 까지 순회하며 체크
    for (i in 1..v) {
        if (group[i] != 0) continue
        group[i] = A
        setGroup(i, group, graph, v)
    }

    // 연결의 양끝이 같은 그룹이면 이분그래프가 아니다
    for (e in edge) {
        if (group[e.first] == group[e.second]) return false
    }
    return true
}

// dfs 를 이용하여 group 을 지정한다 ( A or B )
fun setGroup(cur: Int, group: MutableList<Int>, graph: Array<MutableList<Int>>, v: Int) {
    val nextGroup = if (group[cur] == A) B else A

    for (next in graph[cur]) {
        if (group[next] == NOT_YET) {
            group[next] = nextGroup
            setGroup(next, group, graph, v)
        }
    }
}