import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val N = readLine().toInt()
    val M = readLine().toInt()


    // vip 없이 계산한 자리에 앉는 수
    // dp[n] : n 명이 자리에 앉는 경우의 수
    val dp = IntArray(N + 1) { 0 }
    dp[0] = 1
    for (i in 1..N) {
        val sitOnMySeat = dp[i - 1]
        val sitOnLeftSeat = if (i - 2 >= 0) dp[i - 2] else 0
        dp[i] = sitOnMySeat + sitOnLeftSeat
    }

    var result = 1

    // vip 를 기준으로 끊어서 계산한다
    //  0 0 0 vip 0 0 0 0 vip 0 0
    // -> dp[3] * dp[4] * dp[2] 가 정답!

    var before = 0
    repeat(M) {
        val vip = readLine().toInt()
        result *= dp[vip - before - 1]
        before = vip
    }
    result *= dp[N - before]
    println(result)
}