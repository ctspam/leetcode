class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // the sort function sorts this all lexicographically   

        // next step is where would u store ur ouput?
        // we want to create another list to store all the merged stuff

        vector<vector<int>> mergedIntervals;

        // then we want to have two comparisons which is the start and the end. 
        // so in this we have two cases where the first case is if the end of our current vertex is > than or = tothe start of the next vertex then have the start of the intiial vertex and the end of the next vertex to put created into a vertex
        // the second case if the end of our current vertex is < than the start of the next vertex, then we leave everything alone 

        int currentStart = intervals[0][0];
        int endStart = intervals[0][1];

        for(int i = 1; i < intervals.size(); ++i)
        {
            if (endStart < intervals[i][0])
            {
                mergedIntervals.push_back({currentStart, endStart});
                currentStart = intervals[i][0];
                endStart = intervals[i][1];
            }
            else
            {
                endStart = max(endStart, intervals[i][1]);
            }
        }
        mergedIntervals.push_back({currentStart, endStart});
        return mergedIntervals;
    }
};