/*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max

data class Item(
    var weight: Int,
    var value: Int
) {
    constructor(list: List<Int>) : this(list[0], list[1])
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (n, k) = readLine().split(' ').map { it.toInt() }
    val items = Array<Item>(n + 1) { Item(0, 0) } // weight, value

    repeat(n) { idx ->
        items[idx + 1] = Item(readLine().split(' ').map { it.toInt() })
    }

    val dp = Array(n + 1) { Array(k + 1) { 0 } }

    for (i in 1..n) {
        for (w in 1..k) {
            if (w - items[i].weight < 0) dp[i][w] = dp[i - 1][w]
            else dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i].weight] + items[i].value)
        }
    }

    println(dp[n][k])
}*/
