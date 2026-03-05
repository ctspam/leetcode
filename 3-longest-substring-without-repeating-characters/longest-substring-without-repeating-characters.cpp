class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;                       // left pointer
        int longest = 0;                 // best answer so far
        unordered_set<char> sett;        // stores chars currently in the window

        for (int r = 0; r < (int)s.size(); r++) {     // right pointer expands window
            while (sett.count(s[r])) {                // while s[r] repeats in window
                sett.erase(s[l]);                     // remove leftmost char
                l++;                                  // shrink from the left
            }

            // now window [l..r] has all unique chars
            int w = (r - l) + 1;                      // window length
            longest = max(longest, w);                // update answer
            sett.insert(s[r]);                        // include current char
        }

        return longest;
    }
};