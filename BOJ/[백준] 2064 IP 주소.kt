import java.io.BufferedReader
import java.io.InputStreamReader

fun main() = with(BufferedReader(InputStreamReader(System.`in`))) {
    val n = readLine().toInt()
    val addresses = mutableListOf<List<Int>>()
    val ip = mutableListOf<Int>()
    val networkMask = mutableListOf<Int>()

    repeat(n) {
        addresses.add(readLine().split(".").map { it.toInt() })
    }

    var isFounded = false
    for( it in 0 until 4) {
        val temp = addresses[0][it]
        var isSame = true

        if (isFounded) {
            ip.add(0)
            networkMask.add(0)
            continue
        }

        for (i in 1 until n) {
            if (addresses[i][it] != temp) {
                isSame = false
                break
            }
        }

        if (isSame) {
            networkMask.add(255)
            ip.add(temp)
        } else {
            // 달라지는 지점 check
            var bit = 128 // 1000 000
            var mask = bit
            var breakPoint = false
            while (bit > 0) {
                for (i in 0 until n) {
                    if ((addresses[i][it] and bit) != addresses[0][it] and bit) {
                        breakPoint = true
                        mask -= bit
                        bit *= 2
                        break
                    }
                }

                if (breakPoint) break
                bit /= 2
                mask += bit
            }

            networkMask.add(mask)
            ip.add(addresses[0][it] and mask)
            isFounded = true
        }
    }


    println(ip.joinToString("."))
    println(networkMask.joinToString("."))
}