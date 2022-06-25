import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

val dp = Array(1001) { IntArray(1001) { 0 } }
fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val s1 = readLine()
    val s2 = readLine()

    for (i in 1..s1.length) {
        for (j in 1..s2.length) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1
            } else {
                dp[i][j] = max(
                    dp[i - 1][j],
                    dp[i][j - 1]
                )
            }
        }
    }

    println(dp[s1.length][s2.length])
    printLCS(s1, s2, s1.length, s2.length)
}

fun printLCS(s1: String, s2: String, i: Int, j: Int) {
    if (dp[i][j] == 0) return

    if (s1[i-1] == s2[j-1]) {
        printLCS(s1, s2, i - 1, j - 1)
        print(s1[i - 1])
    } else if (dp[i - 1][j] > dp[i][j - 1]) printLCS(s1, s2, i - 1, j)
    else printLCS(s1, s2, i, j - 1)
}
