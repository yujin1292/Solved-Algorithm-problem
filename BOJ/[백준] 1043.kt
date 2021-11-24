import java.util.*


fun main() = with(Scanner(System.`in`)) {
    val N = nextInt() // 사람 수
    val M = nextInt() // 파티 개수

    // person who know true story
    val people = mutableSetOf<Int>()
    var partyList: MutableList<MutableSet<Int>> = mutableListOf()

    // 사실아는사람 초기화
    val numOfAlreadyKnown = nextInt()
    val checkKnow = Array(N+1) { false }
    for (i in 1..numOfAlreadyKnown) {
        val p = nextInt()
        people.add(p)
        checkKnow[p] = true
    }

    // 파티 인원 초기화
    for (i in 1..M) {
        val count = nextInt()

        val list = mutableSetOf<Int>()
        for (c in 1..count) {
            list.add(nextInt())
        }

        partyList.add(list)
    }

    val queue = people.toMutableList()

    while (queue.isNotEmpty()) {

        val front = queue.first()
        queue.removeAt(0)

        for (party in partyList) {
            if ( front in party ) {
                for( person in party ){
                    if(!checkKnow[person]){
                        checkKnow[person] = true
                        queue.add(person)
                        people.add(person)
                    }
                }
            }
        }

    }

    var result = 0
    for( party in partyList) {
        if (party.intersect(people).isEmpty()) result++
    }
    println(result)
}
