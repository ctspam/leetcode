class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.size(); ++i)
        {
            // a:3, n:1, etcetc
            ++countS[s[i]];
            ++countT[t[i]];
        }

        // equal amount of the letters 
        return countS == countT;


    }
};