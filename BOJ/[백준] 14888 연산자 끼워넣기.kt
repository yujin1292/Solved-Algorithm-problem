import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.lang.Integer.max
import kotlin.math.min

var operators = arrayOf('+','-','*','/')
var operatorCounts = listOf<Int>()
var numbers = listOf<Int>()
var n = 0
var answerMin = Int.MAX_VALUE
var answerMax = Int.MIN_VALUE

fun dfs(counts:Array<Int>, selected: MutableList<Char>) {
    if (selected.size == n-1) {
        var result = numbers.first()
        selected.forEachIndexed { index, c ->
            when(c){
                '+'-> result += numbers[index+1]
                '-' -> result -= numbers[index+1]
                '*' -> result *= numbers[index+1]
                '/' -> result /= numbers[index+1]
            }
        }
        answerMax = max(answerMax, result)
        answerMin = min(answerMin, result)
        return
    }

    // i 가 0 -> 1 -> 2 -> 3 로 늘어가면서 4번 반복하는 함수
    repeat(4){ i ->
        if( counts[i] < operatorCounts[i]){
            selected.add(operators[i])
            counts[i]++
            dfs(counts, selected)
            counts[i]--
            selected.removeLast()
        }
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    n = readLine().toInt()
    numbers = readLine().split(" ").map { it.toInt() }
    operatorCounts = readLine().split(" ").map { it.toInt() }

    dfs( arrayOf(0,0,0,0), mutableListOf())

    bw.run {
        write("$answerMax\n$answerMin")
        flush()
        close()
    }
}