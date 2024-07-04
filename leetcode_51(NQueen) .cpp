The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.





  class Solution {
public:
    vector<int> columns; 
    vector<vector<string>> result;

    // Check if all columns up to 'j' are filled (not used in current implementation)
    bool isComplete(int j, int n) {
        return j == n;
    }

    // Check if the column 'y' is empty
    bool isEmptyColumn(int y) {
        return columns[y] == 0;
    }

    // Check if placing a queen at (x, y) will be attacked by any other queen
    bool attack(int x, int y, vector<vector<int>>& arr) {
        int a = x;
        int b = y;

        // Check vertically above
        while (a >= 0) {
            if (arr[a][b] == 1)
                return false;
            --a;
        }

        // Check left diagonal
        a = x;
        b = y;
        while (a >= 0 && b >= 0) {
            if (arr[a][b] == 1)
                return false;
            --a;
            --b;
        }

        // Check right diagonal
        a = x;
        b = y;
        while (a >= 0 && b < arr.size()) {
            if (arr[a][b] == 1)
                return false;
            --a;
            ++b;
        }
        return true;
    }

    // Recursive function to place queens on the board
    void func(vector<vector<int>>& arr, int n, int x) {
        // If 'x' equals 'n', it means all queens are placed correctly
        if (x == n) {
            vector<string> board;
            for (int i = 0; i < n; ++i) {
                string row = "";
                for (int j = 0; j < n; ++j) {
                    if (arr[i][j] == 1) {
                        row += "Q";
                    } else {
                        row += ".";
                    }
                }
                board.push_back(row);
            }
            result.push_back(board);
            return;
        }

        // Try placing a queen in each column of the current row 'x'
        for (int i = 0; i < n; i++) {
            if (isEmptyColumn(i) && attack(x, i, arr)) {
                arr[x][i] = 1;
                columns[i] = 1;
                func(arr, n, x + 1); // Recur to place a queen in the next row
                arr[x][i] = 0; // Backtrack and remove the queen
                columns[i] = 0; 
            }
        }
    }

    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        columns = vector<int>(n, 0); 
        func(arr, n, 0);
        return result;
    }
};
