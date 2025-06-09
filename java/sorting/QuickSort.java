import java.util.*;

public class Main{

    public static void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public static int partition(int[] nums, int st, int end){ // Time Complexity = O(n)
        int i = st-1;
        int pivot = nums[end];
        for(int j=st; j<end; j++)
        {
            if(nums[j] <= pivot) // for ascending order (nums[j] <= pivot) and for descending order (nums[j] >= pivot).
            {
                i++;
                swap(nums, j, i);
            }
        }
        i++;
        swap(nums, end, i);
        return i;
    }

    public static void quickSort(int[] nums, int st, int end){ // Time Complexity = O(log n)
        if(st < end)
        {
            int pivot = partition(nums, st, end);
            quickSort(nums, st, pivot-1); // left half
            quickSort(nums, pivot+1, end); // right half
        }
    }

    public static void main(String[] args){
        int[] arr = {9,8,7,6,5,4,3,2,1};
        quickSort(arr, 0, arr.length-1); // Time Complexity = O(n log n)
        for(int i: arr)
        {
            System.out.print(i + " ");
        }
        System.out.println();
    }
}