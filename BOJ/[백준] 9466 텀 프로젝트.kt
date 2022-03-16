/*
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

var count = 0
fun dfs(list: List<Int>, finished: MutableList<Boolean>, visited: MutableList<Boolean>, now: Int) {
    if (visited[now]) return

    visited[now] = true
    val next: Int = list[now]

    if (!visited[next]) {
        dfs(list, finished, visited, next)
    }
    else {
        if (!finished[next]) {
            // 노드가 끝나려면 싸이클을 무조건 거쳐야한다.
            // 따라서 현재 노드가 아닌 다음 노드 기준으로 하면 싸이클이 무조건 존재
            count++
            var i = next
            while (i != now) {
                count++
                i = list[i]
            }
        }
    }

    // 모든 작업이 끝나서 더이상 사용하지 않음
    finished[now] = true
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val testCase = readLine().toInt()

    repeat(testCase) {
        val n = readLine().toInt()
        val list = readLine().split(" ").map { it.toInt() - 1 }
        val hasTeam = MutableList(n) { false }
        val isVisited = MutableList(n) { false }
        count = 0
        for (i in 0 until n) {
            dfs(list, hasTeam, isVisited, i)
        }
        bw.write("${n-count}\n")
    }
    bw.flush()
    bw.close()
}*/
