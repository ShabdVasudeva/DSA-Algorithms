#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> nums, int target){ // Time Complexity = O(log n)
    int st = 0, end = nums.size()-1;
    while (st <= end)
    {
        int mid = st+(end-st)/2;
        if (nums[mid] == target)
        {
            return mid; // found the target in nums at index = mid.
        } else if (nums[mid] > target)
        {
            end = mid-1;
        } else
        {
            st = mid+1;
        }
    }

    return -1; // no target found in nums.
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7,8,9};
    int target = 6;
    cout << binarySearch(nums, target) << "\n";
    return 0;
}