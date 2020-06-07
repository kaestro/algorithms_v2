class Solution {
    fun canBeEqual(target: IntArray, arr: IntArray): Boolean {
        val size = target.size

        var idx_start: Int ?= null
        var idx_end: Int ?= null
        for (i in 0..size-1) {
            if (target[i] != arr[i]) {
                if (idx_start == null) {
                    idx_start = i;
                    idx_end = i;
                } else if (idx_end != i - 1) return false;
                else idx_end = i;
            }
        }

        var left = idx_start
        var right = idx_end

        while (left <= idx_end) {
            if (target[left] != arr[right]) return false;
            left++
            right--
        }

        return true
    }
}

fun main() {
    val sol = Solution()
    val target: IntArray = IntArray(4, {it -> it + 1})
    val arr: IntArray = IntArray(4)
    arr[0] = 2; arr[1] = 4; arr[2] = 1; arr[3] = 3;

    print(sol.canBeEqual(target, arr))
}
