Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:





class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>result(rowIndex+1,1);
        for(int i=1;i<rowIndex;i++){
            for(int j=i;j>0;j--){
                result[j]+=result[j-1];
            }
        }
        return result;

        
    }
};
