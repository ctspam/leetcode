class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        //lets say that you take the first number and see if the compliment is in the list, 
        //so you say that 2 is the number and its complemenet is 9-2 = 7. so is 7 in the list?
        //if not we move to the next index, and keep finding the same

        for(int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if(seen.find(complement) != seen.end())
            {
                return{seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};