def swap(nums, a, b):
    nums[a], nums[b] = nums[b], nums[a]  # Swaps elements in the array

def partition(nums, st, end):  # Time Complexity = O(n)
    i = st - 1
    pivot = nums[end]

    for j in range(st, end):
        if nums[j] <= pivot:  # Ascending order (nums[j] <= pivot) & Descending order (nums[j] >= pivot)
            i += 1
            swap(nums, i, j)
    
    i += 1
    swap(nums, i, end)
    return i

def quick_sort(nums, st, end):  # Time Complexity = O(n log n) [Average case], O(n²) [Worst case]
    if st < end:
        pivot = partition(nums, st, end)
        quick_sort(nums, st, pivot - 1)  # Left half
        quick_sort(nums, pivot + 1, end)  # Right half

# Driver Code
arr = [9, 8, 7, 6, 5, 4, 3, 2, 1]
quick_sort(arr, 0, len(arr) - 1)

print("Sorted Array:", arr)