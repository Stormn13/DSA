
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0;
        int left = 0;
        int right = 0;
        int maxx = 0;

        while(right < nums.size()) {
            // Count zeroes
            if(nums[right] == 0) {
                zero++;
            }
            right++;

            // Shrink window if zeroes exceed 1
            while(zero > 1) {
                if(nums[left] == 0) {
                    zero--;
                }
                left++;
            }

            // Update maximum length
            if(right - left > maxx) {
                maxx = right - left;
            }
        }

        return maxx - 1;
    }
};
