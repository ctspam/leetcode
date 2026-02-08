class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //this problem wants you to have two pointers, and left and right 
        //they're both going to start at the same position arrow and then once the
        //right arrow finds the 0, then we will swap with the left arrow
        int n = nums.size();
        int nonzero = 0;
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != 0)
            {
                swap(nums[i], nums[nonzero]);
                ++nonzero;
            }
        }
        return;
    }
};