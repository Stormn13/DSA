class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int a = 0;
        int b = 0;
        int swap = k;
        int local_max = 0;
        int global_max = 0;
        while(b < nums.size()){
            if(nums[b] == 0){
                if(swap > 0){
                    local_max++;
                    swap--;
                    b++;
                }
                else{
                    if(nums[a] == 0){
                        swap++;
                    }
                    a++;
                    local_max--;
                }
            }
            else if(nums[b] == 1){
                local_max++;
                b++;

            }
            if(local_max > global_max){
                global_max = local_max;
            }
        }
        return global_max;
    }
};