class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;  

        for (string s : strs)
        {
            string sortWord = s;
            sort(sortWord.begin(), sortWord.end());
            groups[sortWord].push_back(s);
        }

        vector<vector<string>> allGroups;
        for (const auto& subGroup : groups )
        {
            allGroups.push_back(subGroup.second);
        }
        
        return allGroups;
        // for loops are O(n), length k for sorting o(klogk)
        // TC = O(nk logk), SC = O(nk)
        // eat -> eat
        // tea -> tea

        // aet -> eat,tea, ate
        // ant -> ttan, nat
        // abt -> bat



    }
};