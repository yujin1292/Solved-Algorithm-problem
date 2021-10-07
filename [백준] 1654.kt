
import java.util.*

var K :Int = 0
var N :Int = 0
var ran = mutableListOf<Long>()

fun cut(c: Long) : Long {
    var res = 0L
    for (i in 0 until K){
        if(ran[i] >= c)
            res += (ran[i] /c )
    }
    return res
}

fun bSearch(start: Long, end: Long) : Long {
    var mid = (start+end)/2

    if(start>end) return end

    if(cut(mid) < N ) return bSearch(start,mid-1)
    else return bSearch(mid+1, end)
}

fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    K = nextInt()
    N = nextInt()

    for( i in 1..K){
        var temp = nextLong()
        ran.add(temp)
    }

    ran.sort()
    println(bSearch(1, ran.last()))

}
