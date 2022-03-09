import java.util.*

var N = 0
var M = 0

var num = mutableListOf<Int>()
var result = mutableSetOf<List<Int>>()

fun select( count :Int, selected:MutableList<Int>){
    if( count == M){
        result.add(selected.toList())
        return
    }

    for( i in 0 until N){
        if( selected.isNotEmpty() && selected.last() > num[i]) continue
        selected.add(num[i])
        select( count+1, selected)
        selected.removeAt(selected.size -1)
    }
}

fun main() = with(Scanner(System.`in`)) {
    N = nextInt()
    M = nextInt()

    for ( i in 0 until N){
        num.add(nextInt())
    }
    num.sort()

    select(0, mutableListOf())

    result.forEach{ list->
        println(list.joinToString(" "))
    }
}


