class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        //lets say that you take the first number and see if the compliment is in the list, 
        //so you say that 2 is the number and its complemenet is 9-2 = 7. so is 7 in the list?
        //if not we move to the next index, and keep finding the same,

        // for(int i = 0; i < nums.size(); ++i)
        // {
        //     int complement = target - nums[i];
        //     if(seen.find(complement) != seen.end())
        //     {
        //         return{seen[complement], i};
        //     }
        //     seen[nums[i]] = i;
        // }
        // return {};

        // so approaching this brute force, you want to find its complement
        // and then find its complement and return if its found in the array

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                int complement = target - nums[i];
                if(complement == nums[j])
                {
                    return {i,j};
                }
            }
        }
        return {};

        // TC O(n^2), SC = O(1)
    }
};