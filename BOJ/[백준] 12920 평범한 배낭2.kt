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
    val items = mutableListOf<Item>(Item(0, 0))

    repeat(n) {
        val input = readLine().split(' ').map { it.toInt() }
        val item = Item(input.subList(0, 2))
        var i = input[2]

        // 2진수로 표현해서 전부 나눠서 담아보기. . .
        while (i > 0) {
            val part = i - i / 2
            items.add(Item(item.weight * part, item.value * part))
            i /= 2
        }
    }

    var before = Array(k + 1) { 0 }
    val now = Array(k + 1) { 0 }

    for (i in 1 until items.size) {
        for (w in 1..k) {
            if (w - items[i].weight < 0) now[w] = before[w]
            else now[w] = max(before[w], before[w - items[i].weight] + items[i].value)
        }
        before = now.clone()
    }

    print(before[k])
}