class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> frequency;
        int theDuplicate;

        for (int i = 0; i < nums.size(); ++i)
        {
            ++frequency[nums[i]];
        }

        for (const auto& num : frequency)
        {
            if(num.second >= 2 )
            {
                theDuplicate = num.first;
            }
        }
        return theDuplicate;
    }
};