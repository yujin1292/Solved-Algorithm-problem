import java.lang.Integer.max
import java.util.*


var houses = mutableListOf<Long>()

fun main(args: Array<String>) = with(Scanner(System.`in`)) {

    val N = nextLong()
    val C = nextLong()
    var answer = 0L

    for( i in 1..N){
        var temp = nextLong()
        houses.add(temp)
    }

    houses.sort()

    var start = 1L
    var end = houses.last() - houses.first()

    while( start <= end){
        var mid:Long = (start+end)/2   //가장 인접한 공유기 최대거리

        var prev = houses.first()
        var count = 1 // 첫번째는 설치한것으로 간주

        for( house in houses ){
            if( house-prev >= mid) {
                count++
                prev = house
            }
        }

        if( count >= C ){
            answer = mid
            start = mid + 1
        } else {
            end = mid - 1
        }

    }

    println(answer)
}


