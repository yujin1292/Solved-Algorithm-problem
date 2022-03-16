import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter


val dc = arrayOf(0, 1, 0, -1)
val dr = arrayOf(1, 0, -1, 0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    val n = readLine().toInt()
    val find = readLine().toInt()

    val board = MutableList(n) { MutableList(n) { 0 } }
    var num = n * n
    var (dir, row, col, x, y) = arrayOf(0, 0, 0, 0, 0)

    val moveForward = {
        row += dr[dir]
        col += dc[dir]
    }
    val moveBackward = {
        row -= dr[dir]
        col -= dc[dir]
    }
    val changeDirection = {
        dir++
        dir %= 4
    }

    while (true) {
        board[row][col] = num--
        if (num + 1 == find) {
            x = row + 1
            y = col + 1
        }
        moveForward()
        if (row !in 0 until n || col !in 0 until n || board[row][col] != 0) {
            moveBackward()
            changeDirection()
            moveForward()
        }
        if (num == 0) break
    }

    for (line in board) {
        for (e in line)
            bw.write("$e ")
        bw.write("\n")
    }
    bw.write("$x $y\n")

    bw.flush()
    bw.close()
}