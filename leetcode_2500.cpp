You are given an m x n matrix grid consisting of positive integers.

Perform the following operation until grid becomes empty:

Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
Add the maximum of deleted elements to the answer.
Note that the number of columns decreases by one after each operation.

Return the answer after performing the operations described above.




class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {


int n = grid.size();
        
        int m = grid[0].size();
        
        // sort all the rows
        
        for(int i = 0; i < n; i++)
        {
            sort(grid[i].begin(), grid[i].end());
        }
        
        // traverse over all the columns and find the maximum of all the columns
        
        int sum = 0;
        
        for(int j = 0; j < m; j++)
        {
            int maxi = 0;
            
            for(int i = 0; i < n; i++)
            {
                maxi = max(maxi, grid[i][j]);
            }
            
            sum += maxi;
        }
        
        return sum;
