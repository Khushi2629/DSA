Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:






class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1}; // row 0 is always [1]

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> newRow(i + 1, 1); // create row of size i+1, all 1s

            for (int j = 1; j < i; j++) {
                newRow[j] = row[j - 1] + row[j]; // compute inner elements
            }

            row = newRow; // move to next row
        }

        return row;
    }
};

