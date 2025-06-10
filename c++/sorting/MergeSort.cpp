#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int st, int mid, int end){
    vector<int> temp;
    int i = st, j = mid+1;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        } else
        {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid)
    {
        temp.push_back(nums[i++]);
    }

    while (j <= end)
    {
        temp.push_back(nums[j++]);
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        nums[idx+st] = temp[idx];
    }
}

void mergeSort(vector<int>& nums, int st, int end){
    if (st < end)
    {
        int mid = st+(end-st)/2;
        mergeSort(nums, st, mid);
        mergeSort(nums, mid+1, end);

        merge(nums, st, mid, end);
    }
}

int main(){
    vector<int> nums = {9,8,7,6,5,4,3,2,1};
    mergeSort(nums, 0, nums.size()-1);
    for(int var : nums)
    {
        cout << var << " ";
    }
    cout << "\n";
    return 0;
}