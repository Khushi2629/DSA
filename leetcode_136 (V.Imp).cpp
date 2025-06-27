Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.








class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single =0;
        for(int i=0;i<nums.size();i++){
            single=single^nums[i];        //a ^ a = 0 (any number XOR itself is 0)
                                          // XOR of all twice no would be zero and only that of the single digit remains.
        }
        return single;


        
    }
};
