class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // calculate prefixSum
        int prefix = 0;
        int rem = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        for(int i = 0; i < nums.size(); i++){
            prefix = prefix + nums[i];
            rem = prefix % k;
            if(prefixSum.contains(rem)){
                if(i - prefixSum[rem] >= 2){
                    return true;
                }
            }
            else{
            prefixSum[rem] = i;
            }
        }
        return false;
    }
};