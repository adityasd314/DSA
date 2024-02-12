class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> prev(n, vector<int>(n));
        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
        
        for (int row = 1; row < m; row++) {

            vector<vector<int>> curr(n, vector<int>(n));

            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      //min(n-1, row)   - Explained in video
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { //max(0, n-1-row) - Explained in video
                    
                    int prev_max = 0;
                    //A Robot can come to current column from either column-1, column, or column+1 of prev row (row-1)
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                                prev_max = max(prev_max, prev[column1][column2]);
                        }
                    }
                    
                    if (c1 == c2)
                        curr[c1][c2] = prev_max + grid[row][c1];
                    else
                        curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }
        
        int res = 0;
        //return max in last row 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev[i][j]);    
            }
        }
        return res;
    }
};
