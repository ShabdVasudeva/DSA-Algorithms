fun swap(nums: IntArray, a: Int, b: Int) {
    val temp = nums[a]
    nums[a] = nums[b]
    nums[b] = temp
}

fun partition(nums: IntArray, st: Int, end: Int): Int { // Time Complexity = O(n)
    var i = st - 1
    val pivot = nums[end]

    for (j in st until end) {
        if (nums[j] <= pivot) { // for ascending order (nums[j] <= pivot) and for descending order (nums[j] >= pivot).
            i++
            swap(nums, i, j)
        }
    }
    i++
    swap(nums, i, end)
    return i
}

fun quickSort(nums: IntArray, st: Int, end: Int) { // Time Complexity = O(n log n) [Average case], O(n²) [Worst case]
    if (st < end) {
        val pivot = partition(nums, st, end)
        quickSort(nums, st, pivot - 1) // Left half
        quickSort(nums, pivot + 1, end) // Right half
    }
}

fun main() {
    val arr = intArrayOf(9, 8, 7, 6, 5, 4, 3, 2, 1)
    quickSort(arr, 0, arr.size - 1)

    println(arr.joinToString(" "))
}
