import java.util.*;

public class CheckKnightTour {
    
    public static boolean check(int[][] grid, int row, int col, int n, int val) {
        if(row>=n || col >= n || row<0 || col<0 || grid[row][col] != val) return false;
        if(val == n*n-1) return true;

        boolean ans1 = check(grid, row-2, col-1, n, val+1);
        boolean ans2 = check(grid, row-2, col+1, n, val+1);
        boolean ans3 = check(grid, row-1, col-2, n, val+1);
        boolean ans4 = check(grid, row-1, col+2, n, val+1);
        boolean ans5 = check(grid, row+1, col-2, n, val+1);
        boolean ans6 = check(grid, row+1, col+2, n, val+1);
        boolean ans7 = check(grid, row+2, col+1, n, val+1);
        boolean ans8 = check(grid, row+2, col-1, n, val+1);

        return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);
    }

    public static boolean checkValidGrid(int[][] grid) {
        return check(grid, 0, 0, grid.length, 0);
    }

    public static void main(String[] args) {
        int[][] grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
        System.out.println(checkValidGrid(grid));
    }
}