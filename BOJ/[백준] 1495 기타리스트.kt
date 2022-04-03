import java.io.BufferedReader
import java.io.InputStreamReader

fun main(): Unit = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (N, S, M) = readLine().split(" ").map { it.toInt() }

    val volumeList = mutableListOf(0)
    volumeList.addAll(readLine().split(" ").map { it.toInt() })

    val dp = List(N + 1) { MutableList(M + 1) { false } }
    dp[0][S] = true
    for (song in 0 until N) {
        for (volume in 0..M) {
            if (dp[song][volume]) {
                val increasedVolume = volume + volumeList[song + 1]
                val decreasedVolume = volume - volumeList[song + 1]

                if (increasedVolume in 0..M)
                    dp[song + 1][increasedVolume] = true
                if (decreasedVolume in 0..M)
                    dp[song + 1][decreasedVolume] = true

            }
        }
    }

    var answer = -1
    for (volume in 0..M)
        if (dp[N][volume]) answer = volume
    println(answer)
}

