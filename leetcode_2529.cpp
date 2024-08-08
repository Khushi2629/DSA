Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.





  class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int ans;
    
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                count1++;
            } else if (nums[i]<0){
                count2++;

            }
                
            ans=max(count1,count2);
            



        }
        return ans;
        
    }
};
