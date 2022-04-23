/*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import java.util.Collections.sort

data class Candidate(
    val studentNumber: Int,
    var count: Int,
    var hangTime: Int
) : Comparable<Candidate> {
    override fun compareTo(other: Candidate): Int {
        return if (count.compareTo(other.count) == 0) hangTime.compareTo(other.hangTime)
        else count.compareTo(other.count)
    }

    override fun toString(): String {
        return "($count/$hangTime) $studentNumber"
    }
}


fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {

    val n = readLine().toInt()
    val k = readLine().toInt()
    val recommends = readLine().split(' ').map { it.toInt() }

    // 100명의 학생 객체를 만듦
    val students = List(101) { it }.map { Candidate(it, 0, -1) }
    val frame = PriorityQueue<Candidate>()

    recommends.forEachIndexed { index, recommend ->
        students[recommend].count++

        if (frame.contains(students[recommend])) {
            frame.remove(students[recommend]) // 중간에 값이 바뀌는건 우선순위큐가
            frame.add(students[recommend])   // 정렬을 안하네요 ? .. 그래서 넣었다 뺐습니다
        } else {
            if (frame.size >= n) {
                val removed = frame.poll()
                removed.count = 0
            }
            students[recommend].hangTime = index
            frame.add(students[recommend])
        }
    }

    val answer = mutableListOf<Int>()
    while (frame.isNotEmpty()) {
        answer.add(frame.poll().studentNumber)
    }
    sort(answer)
    print(answer.joinToString(" "))
}
*/
