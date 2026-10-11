class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int p = 0;
        int prefixSum = 0;
        int result = 0;
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        while(p < nums.size()){
            //calculating sum
            prefixSum = prefixSum + nums[p];
            
            if(prefix.contains(prefixSum - k)){
                result = result + prefix[prefixSum-k];
            }
            //adding it to the map
            prefix[prefixSum]++;
            p++;
        }
        return result;
    }
};