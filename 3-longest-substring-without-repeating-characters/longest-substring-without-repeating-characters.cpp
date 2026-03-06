class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, longest = 0;
        size_t n = s.size();
        unordered_set<char> hashSet;
        for(int right = 0; right < n; ++right)
        {
            while(hashSet.count(s[right]))
            {    
                hashSet.erase(s[left]);
                ++left;
            }
            int width = (right - left) + 1;
            longest = max(longest, width);
            hashSet.insert(s[right]);
        }
        return longest;
    }
};