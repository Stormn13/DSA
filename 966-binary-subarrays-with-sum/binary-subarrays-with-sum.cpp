class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefixSum = 0;
        int result = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            prefixSum = prefixSum + nums[i];
            if( (prefixSum - goal) >= 0){
                result = result + prefix[prefixSum - goal];
            }
            prefix[prefixSum]++;

        }
        return result;
    }
};