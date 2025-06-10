def merge(nums, st, mid, end):
    temp = []
    i, j = st, mid + 1

    while i <= mid and j <= end:
        if nums[i] <= nums[j]:
            temp.append(nums[i])
            i += 1
        else:
            temp.append(nums[j])
            j += 1

    while i <= mid:
        temp.append(nums[i])
        i += 1

    while j <= end:
        temp.append(nums[j])
        j += 1

    for idx, value in enumerate(temp):
        nums[st + idx] = value


def merge_sort(nums, st, end):
    if st < end:
        mid = st + (end - st) // 2
        merge_sort(nums, st, mid)
        merge_sort(nums, mid + 1, end)

        merge(nums, st, mid, end)


nums = [9, 8, 7, 6, 5, 4, 3, 2, 1]
merge_sort(nums, 0, len(nums) - 1)
print(nums)