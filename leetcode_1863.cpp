The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.





class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result =0;
        int n=nums.size();
        for(int &num : nums){
            result |=num;      //The |= (bitwise OR assignment) operation combines the current value of result with num. This effectively calculates the bitwise OR of all elements in the array
        }
        return result<< (n-1);     //The bitwise OR result is left-shifted by (n - 1) positions. This is because each bit in result can potentially contribute to 2^(n-1) subsets where n is the length of the array.
        
    }
};
