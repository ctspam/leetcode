class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // we cna make a max heap to ensure that we start with the largest,
        // and then the rest swaps, without SORTING

        priority_queue<int> maxH(nums.begin(), nums.end());

        for (int i = 0; i < k-1; ++i)
        {
            maxH.pop();
        }

        return maxH.top();
    }
};