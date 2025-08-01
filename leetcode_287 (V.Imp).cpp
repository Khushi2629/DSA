Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.



  class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int start=1;
        int end=nums.size()-1;
        while(start < end){
            int mid=start + (end-start)/2;
            int count=0;

            for(int n:nums){
                if(n<=mid){ // For each number in the array, count how many numbers are ≤ mid
                    count++; // Normally, if there’s no duplicate, the count should be ≤ mid but But if count > mid, then the duplicate must be in the lower half
                }
            }
            if (count > mid){.  
                end=mid;
            } else {
                start=mid+1;
            }
        
        }
        return end;
        
    }
};
