class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // unordered_map<string, vector<string>> groups;  

        // for (string s : strs)
        // {
        //     string sortWord = s;
        //     sort(sortWord.begin(), sortWord.end());
        //     groups[sortWord].push_back(s);
        // }

        // vector<vector<string>> allGroups;
        // for (const auto& subGroup : groups )
        // {
        //     allGroups.push_back(subGroup.second);
        // }
        
        // return allGroups;

        // for loops are O(n), length k for sorting o(klogk)
        // TC = O(nk logk), SC = O(nk)
        // eat -> eat
        // tea -> tea

        // aet -> eat,tea, ate
        // ant -> ttan, nat
        // abt -> bat

        unordered_map<string, vector<string>> groups;  

        for (string word : strs)
        {
            vector<int> count(26,0);
            for(char c : word)
            {
                ++count[c-'a'];
            }
            
            string key = "";
            // turn this into a string
            for (int num : count)
            {
                key += to_string(num)  + "|";
            }
            // 1|1|1|1|0|0 -> aet,eat, ate

            groups[key].push_back(word);
        }

        vector<vector<string>> allGroups;
        for (const auto& subGroup : groups )
        {
            allGroups.push_back(subGroup.second);
        }
        
        return allGroups;


    }
};