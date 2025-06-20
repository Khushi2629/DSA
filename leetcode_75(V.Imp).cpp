Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.





  class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0;
        int one=0;
        int two=0;
        for(int n:nums){
            if(n==0) zero++;
            else if(n==1) one++;
            else two++;
        }
        for(int i=0;i<nums.size();++i){
            if(zero>0){
                nums[i]=0;
                zero--;
            } else if(one>0){
                nums[i]=1;
                one--;
            }else {
                nums[i]=2;
                two--;
            }
        }
        
    }
};
