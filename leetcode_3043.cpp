You are given two arrays with positive integers arr1 and arr2.

A prefix of a positive integer is an integer formed by one or more of its digits, starting from its leftmost digit. For example, 123 is a prefix of the integer 12345, while 234 is not.

A common prefix of two integers a and b is an integer c, such that c is a prefix of both a and b. For example, 5655359 and 56554 have a common prefix 565 while 1223 and 43456 do not have a common prefix.

You need to find the length of the longest common prefix between all pairs of integers (x, y) such that x belongs to arr1 and y belongs to arr2.

Return the length of the longest common prefix among all pairs. If no common prefix exists among them, return 0.






  class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        // Convert integer arrays to strings
        vector<string> strArr1, strArr2;
        for (int num : arr1) strArr1.push_back(to_string(num));
        for (int num : arr2) strArr2.push_back(to_string(num));
        
        // Sort both arrays
        sort(strArr1.begin(), strArr1.end());
        sort(strArr2.begin(), strArr2.end());
        
        // Find the longest common prefix between sorted elements
        int maxi = 0;
        int i = 0, j = 0;
        
        while (i < strArr1.size() && j < strArr2.size()) {
            string &first = strArr1[i];
            string &second = strArr2[j];
            
            int k = 0, minLength = min(first.size(), second.size());
            while (k < minLength && first[k] == second[k]) {
                k++;
            }
            
            maxi = max(maxi, k);
            
            // Move to the next comparison
            if (first < second) {
                i++;
            } else {
                j++;
            }
        }
        
        return maxi;
    }
};
