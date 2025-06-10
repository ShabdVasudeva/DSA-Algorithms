fun binarySearch(nums: IntArray, target: Int): Int {  // Time Complexity = O(log n)
    var st = 0
    var end = nums.size - 1
    while (st <= end) {
        val mid = st + (end - st)
        when {
            nums[mid] == target -> return mid // found the target in nums at index = mid.
            nums[mid] > target -> end = mid - 1
            else -> st = mid + 1
        }
    }
    return -1 // no target found in nums.
}

fun main() {
    val nums = intArrayOf(1, 2, 3, 4, 5, 6, 7, 8, 9)
    val target = 6
    println(binarySearch(nums, target))
}
