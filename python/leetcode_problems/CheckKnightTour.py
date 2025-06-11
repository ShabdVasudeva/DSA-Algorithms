def check(grid, row, col, n, val):
    if row >= n or col >= n or row < 0 or col < 0 or grid[row][col] != val:
        return False
    if val == n * n - 1:
        return True

    return (
        check(grid, row - 2, col - 1, n, val + 1) or
        check(grid, row - 2, col + 1, n, val + 1) or
        check(grid, row - 1, col - 2, n, val + 1) or
        check(grid, row - 1, col + 2, n, val + 1) or
        check(grid, row + 1, col - 2, n, val + 1) or
        check(grid, row + 1, col + 2, n, val + 1) or
        check(grid, row + 2, col + 1, n, val + 1) or
        check(grid, row + 2, col - 1, n, val + 1)
    )

def check_valid_grid(grid):
    return check(grid, 0, 0, len(grid), 0)

if __name__ == "__main__":
    grid = [
        [0, 11, 16, 5, 20],
        [17, 4, 19, 10, 15],
        [12, 1, 8, 21, 6],
        [3, 18, 23, 14, 9],
        [24, 13, 2, 7, 22]
    ]

    print(check_valid_grid(grid))
