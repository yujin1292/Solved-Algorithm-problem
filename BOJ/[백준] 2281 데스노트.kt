package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min


fun solve(n: Int, m: Int, names: MutableList<Int>, memo: Array<Array<Int>>, idx: Int, pos: Int): Int {
    if (idx >= n) return 0

    // 메모이제이션 응용
    if (memo[idx][pos] != -1) return memo[idx][pos]

    // 다음줄로 넘기기
    val writeNextLine = (m - pos + 1) * (m - pos + 1) + solve(n, m, names, memo, idx + 1, names[idx] + 1)
    // 뒤에 쓰기 못쓸경우 선택안되게 바로 MAX 값 으로
    val writeBack = if (pos + names[idx] <= m) solve(n, m, names, memo, idx + 1, pos + names[idx] + 1) else Int.MAX_VALUE

    memo[idx][pos] = min(writeNextLine, writeBack)
    return memo[idx][pos]
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (n, m) = readLine().split(" ").map { it.toInt() }

    // memo[idx][pos]  idx 번째 이름이 j 위치에 적혔을때의 값 을 임시저장!
    val memo = Array(n + 1) { Array(m + 2) { -1 } }

    val names = mutableListOf<Int>()
    repeat(n) {
        names.add(readLine().toInt())
    }

    println(solve(n, m, names, memo, 0, 0))
}