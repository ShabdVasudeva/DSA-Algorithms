def binarySearch(nums, target): # Time Complexity = O(log n)
    st, end = 0, len(nums)-1
    while(st <= end):
        mid = st+(end-st)//2
        if(nums[mid] == target):
            return mid # target found at index = mid
        elif(nums[mid] > target):
            end = mid-1
        else:
            st = mid+1
    return None # no target found in nums

nums = [1,2,3,4,5,6,7,8,9]
target = 6
print(binarySearch(nums, target))