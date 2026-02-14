class NumArray {
public:
    
    //have to initialize this because will be needing to call it in sumRange
    vector<int> result;

    NumArray(vector<int>& nums) {
        
        size_t numsSize = nums.size();

        //cant use this , so instead push back
        // vector<int> result(numsSize);

        result.push_back(nums[0]);
        for (int i = 1; i < numsSize; ++i)
        {
            result.push_back(result[i-1] + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {

        
        // so now for this you want to return the result of the thing
        // since we have prefixSum, to find ranges, you would take the rresult[right] - result[left-1]
        // this would get u the sum from that specific length
        if(left != 0)
        {
            return (result[right] - result[left-1]);
        }
        return result[right];
        //got an error for this return, because left-1 even when left = 0 willcause runtime error
        // because of this you need an if statement saying that if left = 0, then just return right, loook at first line
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */