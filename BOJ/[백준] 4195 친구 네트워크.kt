/*
import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun getParent(x: Int, parent: MutableList<Int>): Int {
    if (parent[x] == x) return x
    parent[x] = getParent(parent[x], parent)
    return parent[x]
}

// union parent 후, 부모가 가지고 있는 자식들의 수를 저장한다 ( root parent 만 값을 가짐 )
fun unionParent(a: Int, b: Int, parent: MutableList<Int>, count: MutableList<Int>): Int {
    val parentA = getParent(a, parent)
    val parentB = getParent(b, parent)

    if (parentA == parentB) return count[parentA]

    if (parentA < parentB) {
        parent[parentB] = parentA
        count[parentA] += count[parentB]
        count[parentB] = 1
        return count[parentA]
    } else {
        parent[parentA] = parentB
        count[parentB] += count[parentA]
        count[parentA] = 1
        return count[parentB]
    }
}

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val testcase = readLine().toInt()
    val bw = BufferedWriter(OutputStreamWriter(System.out))

    repeat(testcase) {
        val nameToNumber = mutableMapOf<String, Int>()

        val f = readLine().toInt()
        var number = 1
        val parent = mutableListOf<Int>(0)
        val count = mutableListOf<Int>(0)
        repeat(f) {
            val (a, b) = readLine().split(' ')
            if (!nameToNumber.contains(a)) {
                parent.add(number)
                count.add(1)
                nameToNumber[a] = number++
            }
            if (!nameToNumber.contains(b)) {
                parent.add(number)
                count.add(1)
                nameToNumber[b] = number++
            }

            bw.write("${unionParent(nameToNumber[a]!!, nameToNumber[b]!!, parent, count)}\n")
        }
    }
    bw.flush()
    bw.close()
}*/
