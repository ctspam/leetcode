class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[numbers[i]]=i;
        }

        for(int i=0;i<n;i++) {
            int comple=target-numbers[i];
            if(mp.find(comple)!=mp.end()) {
                if((comple==numbers[i]&&mp[comple]!=i)||comple!=numbers[i])
                return {min(mp[comple]+1,i+1),max(mp[comple]+1,i+1)};
            }
        }

        //unordered_set<int> sett = ;
        //int i = 0;
        return {};
    }
};