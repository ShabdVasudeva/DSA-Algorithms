import java.util.*

class CheckKnightTour {

    fun check(grid: Array<IntArray>, row: Int, col: Int, n: Int, value: Int): Boolean {
        if (row >= n || col >= n || row < 0 || col < 0 || grid[row][col] != value) return false
        if (value == n * n - 1) return true

        val ans1 = check(grid, row - 2, col - 1, n, value + 1)
        val ans2 = check(grid, row - 2, col + 1, n, value + 1)
        val ans3 = check(grid, row - 1, col - 2, n, value + 1)
        val ans4 = check(grid, row - 1, col + 2, n, value + 1)
        val ans5 = check(grid, row + 1, col - 2, n, value + 1)
        val ans6 = check(grid, row + 1, col + 2, n, value + 1)
        val ans7 = check(grid, row + 2, col + 1, n, value + 1)
        val ans8 = check(grid, row + 2, col - 1, n, value + 1)

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8
    }

    fun checkValidGrid(grid: Array<IntArray>): Boolean {
        return check(grid, 0, 0, grid.size, 0)
    }
}

fun main() {
    val grid = arrayOf(
        intArrayOf(0, 11, 16, 5, 20),
        intArrayOf(17, 4, 19, 10, 15),
        intArrayOf(12, 1, 8, 21, 6),
        intArrayOf(3, 18, 23, 14, 9),
        intArrayOf(24, 13, 2, 7, 22)
    )
    
    val knightTour = CheckKnightTour()
    println(knightTour.checkValidGrid(grid))
}
