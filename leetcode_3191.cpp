You are given a 
binary array
 nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.




  class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Flip the next three elements
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                ans++;
            }
        }

        // Check if the last elements are all 1s
        for (int i = n - 3; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return ans;
    }
};
