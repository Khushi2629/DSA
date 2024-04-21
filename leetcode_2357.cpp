You are given a non-negative integer array nums. In one operation, you must:

Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
Subtract x from every positive element in nums.
Return the minimum number of operations to make every element in nums equal to 0.




class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] !=0)
            {
                if(pq.empty())
                {
                    pq.push(nums[i]);
                }
                else
                {
                    if(pq.top()==nums[i])
                    {
                        continue;
                    }
                    else
                    {
                        pq.push(nums[i]);
                    }
                }
            }
        }
        return pq.size();

        
    }
};
