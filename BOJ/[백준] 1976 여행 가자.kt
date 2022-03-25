package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val INF = 20000
    val N = readLine().toInt()
    val M = readLine().toInt()

    val graph = mutableListOf<MutableList<Int>>()
    repeat(N) {
        val line = readLine().split(" ")
            .map { if (it.toInt() == 0) INF else 1 }
            .toMutableList()
        graph.add(line)
    }

    // floyd - warshall

    for (k in 0 until N) {
        for (i in 0 until N) {
            for (j in 0 until N) {
                if (graph[i][j] > graph[i][k] + graph[k][j])
                    graph[i][j] = graph[i][k] + graph[k][j]
            }
        }
    }


    val plan = readLine().split(" ").map { it.toInt() - 1 }

    for (i in 0 until M - 1) {
        val from = plan[i]
        val to = plan[i + 1]
        if( from == to) continue // INF 이지만 갈 수있는거라서 . .
        if (graph[from][to] == INF) {
            println("NO")
            return@with
        }
    }

    println("YES")
}