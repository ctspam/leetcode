class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //for this you want to start wihttt the first number and then use the complement to find if there's any matching
        //lets create a hashmap for this

        unordered_map<int,int> findMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            //next you want to mark the first  num and find its complemenmmt
            int num = nums[i];
            int complement = target - num;
            
            //then you want to find if the complement even existst in the array
            if(findMap.find(complement) != findMap.end()) return {findMap[complement], i};

            findMap[num] = i;
        }

        return {};
    }
};