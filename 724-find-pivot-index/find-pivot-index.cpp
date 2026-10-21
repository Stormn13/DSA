class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int Lsum = 0;
        int Rsum = 0;
        //compute Rsum
        for(int i = 0; i < nums.size(); i++){
            Rsum = Rsum + nums[i];
        }
        //itertate the pointer and update Lsum and Rsum
        for(int j = 0; j < nums.size(); j++){

            //change the Rsum
            Rsum = Rsum - nums[j]; 
            
            if(Lsum == Rsum){
                return j;
            }
            //change the Lsum 
            Lsum = Lsum + nums[j];

     
        }
        return -1;
    }
};