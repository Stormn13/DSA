class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int last_overlap = 0;

        for(int i = 0; i < intervals.size(); i++){

            // No overlap: existing interval is before newInterval
            if(intervals[i][1] < newInterval[0]){
                result.push_back(intervals[i]);
                last_overlap++;
            }

            // No overlap: existing interval is after newInterval
            else if(intervals[i][0] > newInterval[1]){
                result.push_back(intervals[i]);
            }

            // Overlap: merge
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.insert(result.begin() + last_overlap, newInterval);

        return result;
    }
};