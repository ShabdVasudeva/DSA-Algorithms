import java.util.*

fun merge(nums: IntArray, st: Int, mid: Int, end: Int) {
    val temp = mutableListOf<Int>()
    var i = st
    var j = mid + 1

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j]) {
            temp.add(nums[i])
            i++
        } else {
            temp.add(nums[j])
            j++
        }
    }

    while (i <= mid) {
        temp.add(nums[i])
        i++
    }

    while (j <= end) {
        temp.add(nums[j])
        j++
    }

    for ((idx, value) in temp.withIndex()) {
        nums[st + idx] = value
    }
}

fun mergeSort(nums: IntArray, st: Int, end: Int) {
    if (st < end) {
        val mid = st + (end - st) / 2
        mergeSort(nums, st, mid)
        mergeSort(nums, mid + 1, end)

        merge(nums, st, mid, end)
    }
}

fun main() {
    val nums = intArrayOf(9, 8, 7, 6, 5, 4, 3, 2, 1)
    mergeSort(nums, 0, nums.size - 1)
    println(nums.joinToString(" "))
}
