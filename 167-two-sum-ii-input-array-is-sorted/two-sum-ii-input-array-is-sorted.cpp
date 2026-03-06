class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();

        for(int i=0;i<n;i++) {
            int comple=target-numbers[i];
            // binary search for non-decreasing
            int lo=-1, hi=n-1;
            while(lo<hi) {
                int mid=lo+(hi-lo+1)/2;
                if(numbers[mid]<=comple) lo=mid;
                else hi=mid-1; 
            }
            if(lo!=-1&&numbers[lo]==comple) {
                // cout<<i<<" "<<lo<<" "<<numbers[i]<<" "<<comple<<'\n';
                if(comple==numbers[i]) {
                    // right-most 
                    if(lo==i) {
                        if(lo-1>=0) {
                            if(numbers[lo-1]==numbers[i]) return {min(lo+1,i+1),max(lo+1,i+1)};
                        } else return {};
                    } else return {min(lo+1,i+1),max(lo+1,i+1)};
                } 
                else 
                return {min(lo+1,i+1),max(lo+1,i+1)};
            }
        }

        //unordered_set<int> sett = ;
        //int i = 0;
        return {};
    }
};