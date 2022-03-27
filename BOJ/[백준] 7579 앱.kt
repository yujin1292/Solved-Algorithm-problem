package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (N, M) = readLine().split(" ").map { it.toInt() }

    val memory = mutableListOf<Int>(0)
    memory.addAll(readLine().split(" ").map { it.toInt() })

    val cost = mutableListOf<Int>(0)
    cost.addAll(readLine().split(" ").map { it.toInt() })

    val maxCost = cost.sum()
    val dp = Array(N + 1) { IntArray(maxCost + 1) { 0 } }

    // dp[i][j] -> i 번째 앱까지 고려해서 j의 비용을 사용하고 얻은 최대 memory
    for (i in 1..N) {
        for (j in 0..maxCost) {
            if (j - cost[i] !in 0..maxCost) dp[i][j] = dp[i - 1][j]
            else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i - 1][j - cost[i]] + memory[i]
                )
            }
        }
    }

    for (i in 0..maxCost) {
        if (dp[N][i] >= M) {
            println(i)
            break
        }
    }
}