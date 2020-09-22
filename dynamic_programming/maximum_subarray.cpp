class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int arrLen=nums.size();
        int maxSum= numeric_limits<int>::min();
        int currSum=numeric_limits<int>::min();
        int idx=0;
        
        for( idx=0; idx<arrLen;idx++){
            if(nums[idx]>0){
                currSum = nums[idx];
                maxSum=nums[idx];
                break;
            }
            else{
                if(currSum<nums[idx]){
                    currSum = nums[idx];
                    maxSum = currSum;
                }
            }
        }
        idx++;
        while(idx<arrLen){
            if(currSum+nums[idx] > 0){
                currSum=currSum+nums[idx];
                if(maxSum < currSum)
                    maxSum = currSum;
            }
            else{
                currSum =0;        
            }
            idx++;
        }
      return maxSum;  
    }
};
