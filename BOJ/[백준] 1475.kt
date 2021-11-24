import java.util.*

fun main()  = with(Scanner(System.`in`)) {

    var roomNumber = next()
    var countNums = IntArray(10) {0}
    var sixNine = 0
    for( num in roomNumber) {
        if(num.digitToInt() == 6 || num.digitToInt() == 9 )
            sixNine++
        else
            countNums[num.digitToInt()]++
    }

    val max = countNums.maxOrNull()!!

    sixNine++

    if( max > sixNine)
        println(max)
    else{
        if( max > sixNine/2)
            println(max)
        else
            println(sixNine/2)
    }

}
