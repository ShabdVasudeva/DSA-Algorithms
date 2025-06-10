import java.util.*;

class BinarySearch {

    public static int binarySearch(int[] nums, int target){ // Time Complexity = O(log n)
        int st = 0;
        int end = nums.length-1;
        while(st <= end)
        {
            int mid = st+(end-st);
            if(nums[mid] == target)
            {
                return mid; // found the target in nums at index = mid.
            } else if(nums[mid] > target)
            {
                end = mid-1;
            } else 
            {
                st = mid+1;
            }
        }
        return -1; // no target found in nums.
    }

    public static void main(String[] args){
        int[] nums = {1,2,3,4,5,6,7,8,9};
        int target = 6;
        System.out.println(binarySearch(nums, target));
    }
}