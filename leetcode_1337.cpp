You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

A row i is weaker than a row j if one of the following is true:

The number of soldiers in row i is less than the number of soldiers in row j.
Both rows have the same number of soldiers and i < j.
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.






  class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m= mat[0].size();
        vector<int>ans;
        vector<pair<int,int>>res;
        for(int i=0;i<n;i++){
            int sum=accumulate(mat[i].begin(),mat[i].end(),0);
            res.push_back({sum,i});
        }
        sort(res.begin(),res.end());
        for(int i=0;i<k;i++) ans.push_back(res[i].second);
        return ans;


        
    }
};
