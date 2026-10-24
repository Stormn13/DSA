class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int pointer = 0;
        int start = 0;
        int end = 0;
        int result = 0;
        int lastInRange = -1;

        for (pointer = 0; pointer < nums.size(); pointer++) {
            if (nums[pointer] > right) {
                start = pointer + 1;
                lastInRange = -1;
            }
            else {
                if (nums[pointer] >= left) {
                    lastInRange = pointer;
                }

                if (lastInRange != -1) {
                    result += lastInRange - start + 1;
                }
            }
            end = pointer;
        }

        return result;
    }
};