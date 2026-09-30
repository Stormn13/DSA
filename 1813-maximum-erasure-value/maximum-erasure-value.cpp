class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        unordered_set<int> track;
        int a = 0;
        int b = 1;
        int local_sum = 0;
        int max_sum = 0;
        track.insert(nums[a]);
        local_sum = local_sum + nums[a];
        while(b < nums.size()){
            if(track.contains(nums[b])){
                track.erase(nums[a]);
                local_sum = local_sum - nums[a];
                a++;
                continue;
            }
            else{
                track.insert(nums[b]);
                local_sum = local_sum + nums[b];
                b++;
            }
            if(local_sum > max_sum){
                max_sum = local_sum;
            }
            
        }
        return max_sum;

    }
};