class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size()/2;
        if (n%2 != 1) n--;
        //unordered_set<int> sett = ;
        //int i = 0;
        int left= 0;
        int right = numbers.size()-1;
        while (left!= right) 
        {
             
            if (numbers[left] + numbers[right] == target) return {left+1, right+1};
            else if (numbers[left] + numbers[right] > target)
            {
                right--;
            }
            else if (numbers[left] + numbers[right] < target )
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
        }
        return {};
    }
};