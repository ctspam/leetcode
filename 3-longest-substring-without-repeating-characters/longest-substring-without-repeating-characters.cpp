class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;  
        int result = 0;  // Length of longest substring found so far.
        int start = 0;  // Start index of current substring with unique characters.
        // Track if a character is in [start, i]. `char` is 8-bit (hence 256 possibilties).
        // More generic, but slower, would be a std::unordered_set<char>.
        vector<bool> chars_in_substring;
        chars_in_substring.resize(256);
        for (int i = 0; i < s.size(); ++i) {
            // Advance `start` until [start, i] contains only unique characters.
            // This means s[i] cannot be in [start, i-1].
            while (chars_in_substring[s[i]]) {
                chars_in_substring[s[start++]] = false;
            }
            chars_in_substring[s[i]] = true;
            // Is this our new longest substring?
            result = max(result, i-start+1);	
        }
        return result;
    }
};