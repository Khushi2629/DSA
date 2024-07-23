Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

Return the sorted array.






  class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(int num: nums){
            freq[num]++;

        }

        sort(nums.begin(),nums.end(), [&](int n1, int n2){
            if(freq[n1]!= freq[n2]) {
                return freq[n1] < freq[n2];
            }else{
                return n2<n1;
            }
        });

        return nums;
        
    }
};
