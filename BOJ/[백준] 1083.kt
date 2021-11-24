import java.util.*

var N: Int = 0
var S: Int = 0
var arr = mutableListOf<Int>()

fun main() = with(Scanner(System.`in`)) {
    N = nextInt()
    for (i in 1..N)
        arr.add(nextInt())
    S = nextInt()

    for (idx in 0 until N) {
        var maxIdx = idx
        var max = 0
        for( i in idx until N){
            if( S < i - idx) break
            if( max < arr[i]){
                maxIdx = i
                max = arr[i]
            }
        }
        S -= (maxIdx-idx)
        for( i in maxIdx downTo idx+1 ){
            val temp = arr[i]
            arr[i] = arr[i-1]
            arr[i-1] = temp
        }
    }

    println(arr.joinToString(" "))
}
