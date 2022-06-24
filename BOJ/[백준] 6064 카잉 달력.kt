import java.io.BufferedReader
import java.io.InputStreamReader


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val stringBuilder = StringBuilder()
    repeat(readLine().toInt()) {
        val (M, N, x, y) = readLine().split(" ").map { it.toInt() }
        stringBuilder.append("${solve(M, N, x, y)}\n")
    }

    print(stringBuilder.toString())
}

fun gcd(A: Int, B: Int): Int {
    var a = A
    var b = B

    while (b > 0) {
        val temp = b
        b = a % b
        a = temp
    }
    return a
}

fun lcm(a: Int, b: Int): Int {
    return a * (b / gcd(a, b))
}

fun solve(M: Int, N: Int, x: Int, y: Int): Int {
    val len = lcm(M, N)

    for (count in x..len step M) {
        val a = (count - 1) % M + 1
        val b = (count - 1) % N + 1

        if (a == x && b == y) {
            return count
        }
    }
    return -1
}