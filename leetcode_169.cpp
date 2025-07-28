Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



  class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ans=nums[n/2];
        return ans;

    }
};
