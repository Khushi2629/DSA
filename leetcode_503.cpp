Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.





  class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);    //no greater element found → -1
        stack<int>st;
        for(int i=0;i < 2*n;i++){    //bcoz the array is circular
            int index = i % n;    // ensures we wrap around

            while(!st.empty() && nums[index] > nums[st.top()]){
                ans[st.top()]= nums[index];
                st.pop();
            }
            if(i<n) st.push(index);
            


        }
        return ans;


        
    }
};
