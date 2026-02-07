class Solution {
public:
    bool isAnagram(string s, string t) {
        //firtst we want to check even if the lengths are correct
        if(s.length() != t.length()) return false;

         //the best way to approach this is to use a hash map
         //creating two hashmaps one for string s and string t, and then comparing the values 
         unordered_map<char, int> countS;
         unordered_map<char, int> countT;

         //now traverse each letter in the string
         for(int i = 0; i < s.length(); ++i)
         {
            ++countS[s[i]];
            ++countT[t[i]];
            //doing this allows the count of each letter in the word
         }

         return countS == countT;
    }
};