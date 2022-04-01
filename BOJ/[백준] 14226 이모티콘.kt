import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

data class Status(
    val clipboard: Int, //클립보드에 담긴 이모티콘 수
    val screen: Int // 화면에 출력되어있는 이모티콘 수
)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val s = readLine().toInt()

    val q: Queue<Status> = LinkedList()
    val duplicated = mutableSetOf<Status>()

    q.offer(Status(clipboard = 0, screen = 1))
    duplicated.add(Status(clipboard = 0, screen = 1))

    var time = 0
    while (q.isNotEmpty()) {
        val size = q.size
        for (i in 0 until size) {
            val front = q.poll() ?: break
            if (front.screen == s) {
                println(time)
                q.clear()
                break
            }

            // 클립보드에 복사
            val copy = Status(clipboard = front.screen, screen = front.screen)
            if (!duplicated.contains(copy)) {
                q.offer(copy)
                duplicated.add(copy)
            }

            // 붙여넣기
            if (front.clipboard != 0) {
                val pasted = Status(clipboard = front.clipboard, screen = front.screen + front.clipboard)
                if (!duplicated.contains(pasted)) {
                    q.offer(pasted)
                    duplicated.add(pasted)
                }
            }

            // 화면에서 하나 삭제
            if (front.screen > 0) {
                val deleted = Status(clipboard = front.clipboard, screen = front.screen - 1)
                if (!duplicated.contains(deleted)) {
                    q.offer(deleted)
                    duplicated.add(deleted)
                }
            }

        }
        time++
    }
}