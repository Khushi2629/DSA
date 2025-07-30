Given an integer array nums, find the subarray with the largest sum, and return its sum.


  class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum <=0){    // to handle if there is any negative or 0 value
                currsum=0;      // reset to 0
            }
        }
        return maxsum;

        
    }
};
