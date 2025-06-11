#include <iostream>
#include <vector>

using namespace std;

bool check(vector<vector<int>>& grid, int row, int col, int n, int val) {
    if(row>=n || col >= n || row<0 || col<0 || grid[row][col] != val) return false;
    if(val == n*n-1) return true;

    bool ans1 = check(grid, row-2, col-1, n, val+1);
    bool ans2 = check(grid, row-2, col+1, n, val+1);
    bool ans3 = check(grid, row-1, col-2, n, val+1);
    bool ans4 = check(grid, row-1, col+2, n, val+1);
    bool ans5 = check(grid, row+1, col-2, n, val+1);
    bool ans6 = check(grid, row+1, col+2, n, val+1);
    bool ans7 = check(grid, row+2, col+1, n, val+1);
    bool ans8 = check(grid, row+2, col-1, n, val+1);

    return (ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8);
}

bool checkValidGrid(vector<vector<int>>& grid) {
    return check(grid, 0, 0, grid[0].size(), 0);
}

int main(){
    vector<vector<int>> grid = {{0,11,16,5,20},{17,4,19,10,15},{12,1,8,21,6},{3,18,23,14,9},{24,13,2,7,22}};
    cout << checkValidGrid(grid) << "\n";
    return 0;
}