You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.




class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        while (start< end){
            int mid=start + (end-start)/2;
            if(mid % 2 ==1){ // mid must be even, because pairs start at even indices in sorted arrays
                mid--;
            }
            if(nums[mid] != nums[mid+1]){
                end=mid;
            }else{
                start=mid+2;
            }

        }
        return nums[end];
        
    }
};
