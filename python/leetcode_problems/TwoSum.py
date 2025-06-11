class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashMap: dict = dict()
        for i in range(len(nums)):
            num: int = target - nums[i]
            if(num in hashMap):
                return [i, hashMap[num]]
            hashMap[nums[i]] = i
        return None