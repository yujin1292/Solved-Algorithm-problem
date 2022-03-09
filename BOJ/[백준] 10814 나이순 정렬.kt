import java.util.*
import java.util.Collections.sort

data class User(
    var signedUpTime: Int, var age: Int, var name: String
) : Comparable<User> {
    // age 선비교 후 같을경우 signedUpTime 으로 비교
    override fun compareTo(other: User): Int {
        return if (age.compareTo(other.age) == 0) signedUpTime.compareTo(other.signedUpTime)
        else age.compareTo(other.age)
    }
    // 출력하기 편하려고 toString 오버라이딩 했슴니다
    override fun toString(): String = "$age $name"
}

fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    val users = mutableListOf<User>()
    repeat(n) {
        val temp = nextLine().split(" ")
        users.add(User(it, temp[0].toInt(), temp[1]))
    }
    sort(users)
    for (user in users) println(user)
}