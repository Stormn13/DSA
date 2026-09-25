class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //Convert array to binary array
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                nums[i] = 0;
            } else {
                nums[i] = 1;
            }
        }
        
        //Count subarrays using Prefix Sum
        unordered_map<int, int> oddFreq;
        oddFreq[0] = 1; 
        int oddCount = 0; 
        int result = 0;
        
        for(int i = 0; i < nums.size(); i++){
            oddCount += nums[i]; 
            
            if(oddFreq.count(oddCount - k)){
                result += oddFreq[oddCount - k];
            }
            
            oddFreq[oddCount]++;
        }
        
        return result;
    }
};