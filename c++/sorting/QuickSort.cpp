#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int st, int end){ // Time Complexity = O(n)
    int i = st-1, pivot = nums[end];
    for (int j = st; j < end; j++)
    {
        if (nums[j] <= pivot) // for ascending order (nums[j] <= pivot) and for descending order (nums[j] >= pivot).
        {
            i++;
            swap(nums[j], nums[i]);
        }
    }
    i++;
    swap(nums[end], nums[i]);
    return i;
}

void quickSort(vector<int>& nums, int st, int end){ // Time Complexity = O(log n)
    if (st < end)
    {
        int pivot = partition(nums, st, end);
        quickSort(nums, st, pivot-1); // left half
        quickSort(nums, pivot+1, end); // right half
    }
}

int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    quickSort(arr, 0, arr.size()-1); // Time Complexity = (n log n)
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}