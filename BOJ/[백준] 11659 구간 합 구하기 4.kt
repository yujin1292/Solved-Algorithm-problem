package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val (N, M) = readLine().split(" ").map { it.toInt() }
    val numbers = readLine().split(" ").map { it.toInt() }.toMutableList()

    numbers.add(index = 0, element = 0)
    for (i in 1..N) numbers[i] += numbers[i - 1]

    val sb = StringBuilder()
    repeat(M) {
        val (a, b) = readLine().split(' ').map { it.toInt() }
        sb.append("${numbers[b] - numbers[a - 1]}\n")
    }
    print(sb.toString())
}