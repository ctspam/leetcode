class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        // useprefix sum array

        // get ur prefix arr
        size_t numsSize = nums.size();
        vector<int> prefixArr(numsSize);
        
        //then make prefix and nums [0] ==
        prefixArr[0] = nums[0];

        // you start at one for the nums array
        for(int i = 1; i < numsSize; ++i)
        {
            prefixArr[i] = prefixArr[i-1] + nums[i];
        }

        return prefixArr;
    }
};