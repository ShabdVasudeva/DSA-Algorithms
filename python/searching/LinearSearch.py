def linearSearch(nums, target): # Time Complexity = O(n)
    for i in range(len(nums)-1):
        if(nums[i] == target):
            return i
    return None

nums = [1,2,3,4,5,6,7,8,9]
target = 6
print(linearSearch(nums, target))