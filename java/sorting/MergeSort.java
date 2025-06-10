import java.util.*;

public class MergeSort{

    public static void merge(int[] nums, int st, int mid, int end){
        ArrayList<Integer> temp = new ArrayList<Integer>();
        int i = st;
        int j = mid+1;
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
            {
                temp.add(nums[i]);
                i++;
            } else 
            {
                temp.add(nums[j]);
                j++;
            }
        }

        while(i <= mid)
        {
            temp.add(nums[i]);
            i++;
        }

        while(j <= end)
        {
            temp.add(nums[j]);
            j++;
        }

        for(int idx = 0; idx < temp.size(); idx++)
        {
            nums[idx+st] = temp.get(idx);
        }
    }

    public static void mergeSort(int[] nums, int st, int end){
        if(st < end)
        {
            int mid = st+(end-st)/2;
            mergeSort(nums, st, mid);
            mergeSort(nums, mid+1, end);

            merge(nums, st, mid, end);
        }
    }

    public static void main(String[] args){
        int[] nums = {9,8,7,6,5,4,3,2,1};
        mergeSort(nums, 0, nums.length-1);
        for(int i: nums)
        {
            System.out.println(i+" ");
        }
    }
}