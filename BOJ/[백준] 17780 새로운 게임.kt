import java.io.BufferedReader
import java.io.InputStreamReader


// right left up down
val dr = arrayOf(0, 0, -1, 1)
val dc = arrayOf(1, -1, 0, 0)

// 가독성을 위해 굳이 만든겁니다.. 낫 필수 ..
const val WHITE = "0"
const val RED = "1"
const val BLUE = "2"

data class Piece(
    var row: Int,
    var col: Int,
    var direction: Int,
    var number: Int = -1
) {
    constructor(list: List<String>) : this(
        row = list[0].toInt() - 1,
        col = list[1].toInt() - 1,
        direction = list[2].toInt() - 1
    )

    fun reverseDirection() {
        direction = when (direction) {
            0 -> 1
            1 -> 0
            2 -> 3
            3 -> 2
            else -> -1 // 이럴수는없지만 else 있어야 돌아가서 ..
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val (N, K) = readLine().split(' ').map { it.toInt() }

    // 체스판의 색만 저장
    val boardColor = mutableListOf<List<String>>()

    // 체스말들의 정보를 담음
    val pieces = mutableListOf<Piece>()

    // 체스판 위에 올라와있는 말 정보
    val board = Array(N) { Array(N) { mutableListOf<Int>() } }

    repeat(N) {
        boardColor.add(readLine().split(' '))
    }
    repeat(K) {
        val p = Piece(readLine().split(' '))
        p.number = it
        pieces.add(p)
        board[p.row][p.col].add(it)
    }


    val moveToWhite: (Piece) -> Unit = { piece ->
        val nextRow = piece.row + dr[piece.direction]
        val nextCol = piece.col + dc[piece.direction]

        board[nextRow][nextCol].addAll(board[piece.row][piece.col])
        board[piece.row][piece.col].clear()
        for (p in board[nextRow][nextCol]) {
            pieces[p].row = nextRow
            pieces[p].col = nextCol
        }
    }

    val moveToRed: (Piece) -> Unit = { piece ->
        val nextRow = piece.row + dr[piece.direction]
        val nextCol = piece.col + dc[piece.direction]

        board[piece.row][piece.col].reverse()
        board[nextRow][nextCol].addAll(board[piece.row][piece.col])
        board[piece.row][piece.col].clear()
        for (p in board[nextRow][nextCol]) {
            pieces[p].row = nextRow
            pieces[p].col = nextCol
        }
    }

    // 체스말의 움직이고, 움직인 후의 위치 반환까지하는 함수
    val moveToBlueOrOutRange: (Piece) -> Pair<Int, Int> = { piece ->
        //방향바꾸기
        piece.reverseDirection()

        // 방향 바꾼후의 움직일 위치
        var nextRow = piece.row + dr[piece.direction]
        var nextCol = piece.col + dc[piece.direction]

        if (nextRow in 0 until N && nextCol in 0 until N) {
            when (boardColor[nextRow][nextCol]) {
                BLUE -> {/* do nothing */
                    nextRow = piece.row
                    nextCol = piece.col
                }
                RED -> {
                    moveToRed(piece)
                }
                WHITE -> moveToWhite(piece)
            }
        } else { // 다음위치가 범위를 벗어났으므로 do nothing
            nextRow = piece.row
            nextCol = piece.col
        }


        Pair(nextRow, nextCol)
    }

    for (turn in 0 until 1_000) {
        for (piece in pieces) {

            // 가장 아래에 있는 말이 아니므로 안움직이고 건너 뜀
            if (board[piece.row][piece.col].first() != piece.number) continue

            var nextRow = piece.row + dr[piece.direction]
            var nextCol = piece.col + dc[piece.direction]

            if (nextRow !in 0 until N || nextCol !in 0 until N) {
                // out of range

                val movedPosition = moveToBlueOrOutRange(piece)
                nextRow = movedPosition.first// 방향이 바뀌었기때문에
                nextCol = movedPosition.second

            } else {
                when (boardColor[nextRow][nextCol]) {
                    WHITE -> {
                        moveToWhite(piece) // white와 red의 경우 방향전환이없어서 nextRow, col 변화 안줘도됨
                    }
                    RED -> {
                        moveToRed(piece)
                    }
                    BLUE -> {
                        val movedPosition = moveToBlueOrOutRange(piece)
                        nextRow = movedPosition.first// 방향이 바뀌었기때문에
                        nextCol = movedPosition.second
                    }
                }
            }

            // 말이 4개이면 도중 중단
            if (board[nextRow][nextCol].size >= 4) {
                println(turn + 1)
                return@with
            }
        }

    }

    println(-1)
}