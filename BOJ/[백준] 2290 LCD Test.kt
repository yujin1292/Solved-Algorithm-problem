package boj

import java.io.BufferedReader
import java.io.InputStreamReader


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (temp, N) = readLine().split(" ")
    val s = temp.toInt()
    val len = N.length


    // flag[area][number]
    val flags = mutableListOf(
        //             0      1      2      3     4      5       6     7       8    9
        mutableListOf(true, false, false, false, true, true, true, false, true, true),
        mutableListOf(true, false, true, false, false, false, true, false, true, false),
        mutableListOf(true, true, true, true, true, false, false, true, true, true),
        mutableListOf(true, true, false, true, true, true, true, true, true, true),
        mutableListOf(true, false, true, true, false, true, true, true, true, true),
        mutableListOf(false, false, true, true, true, true, true, false, true, true),
        mutableListOf(true, false, true, true, false, true, true, false, true, true),
    )

    val display = Array(2 * s + 3) { CharArray((s + 2) * len + (len - 1)) { ' ' } }

    val fill: (Int, Int) -> Unit = { pos, areaNumber ->
        if (areaNumber < 4) { // 세로로 S 개
            val row = if (areaNumber % 2 == 0) 1 else 2 + s
            val col = if (areaNumber < 2) pos else pos + (s + 1)
            repeat(s) {
                display[row + it][col] = '|'
            }
        } else { // 가로로 S 개
            val row = (areaNumber - 4) * (s + 1)
            val col = pos + 1
            repeat(s) {
                display[row][col + it] = '-'
            }
        }
    }


    for (i in N.indices) {
        val number = N[i] - '0'
        val startPosition = i * (s + 3)
        for (area in 0..6) {
            if (flags[area][number]) {
                fill(startPosition, area)
            }
        }
    }

    // display 출력
    for (row in display) {
        for (element in row) {
            print(element)
        }
        println()
    }
}