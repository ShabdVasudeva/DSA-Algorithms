fun linearSearch(nums: IntArray, target: Int): Int { // Time Complexity = O(n)
    for (i in nums.indices) {
        if (nums[i] == target) {
            return i
        }
    }
    return -1
}

fun main() {
    val nums = intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val target = 6
    println(linearSearch(nums, target))
}
