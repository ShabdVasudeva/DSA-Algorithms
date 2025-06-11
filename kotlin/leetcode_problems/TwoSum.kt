import java.util.*

class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val hashMap: HashMap<Int, Int> = HashMap<Int, Int>()
        for(i in 0 .. (nums.size-1)){
            val num: Int = target-nums[i]
            if(hashMap.containsKey(num)){
                return intArrayOf(i, hashMap.get(num)!!)
            }
            hashMap.put(nums[i], i)
        }
        return intArrayOf()
    }
}