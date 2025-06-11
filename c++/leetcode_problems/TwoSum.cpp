#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];
            if (hashMap.find(num) != hashMap.end())
            {
                return {i, hashMap[num]};
            }
            hashMap[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int> ans = solution.twoSum(nums, target);
    cout << ans[0] << " : " << ans[1] << "\n";
    return 0;
}