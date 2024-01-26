 using Matrix = vector<vector<vector<int>>>;

class Solution {
public:
    bool isOutOfGrid(int m, int n, int i, int j) {
        return i < 0 || i >= m || j < 0 || j >= n;
    }

    int solve(int m, int n, int move, int startRow, int startColumn, Matrix &memo) {
        if (move == 0) {
            return 0;
        }

        if (memo[startRow][startColumn][move] !=-1) {
            return memo[startRow][startColumn][move];
        }

        long long int paths = 0;
        const int MOD = 1000000007;

        if (move == 1) {
            paths += isOutOfGrid(m, n, startRow + 1, startColumn);
            paths += isOutOfGrid(m, n, startRow, startColumn + 1);
            paths += isOutOfGrid(m, n, startRow - 1, startColumn);
            paths += isOutOfGrid(m, n, startRow, startColumn - 1);
            memo[startRow][startColumn][move] = paths % MOD;

            return paths % MOD;
        } else {

            if (!isOutOfGrid(m, n, startRow + 1, startColumn)) {
                
                paths += solve(m, n, move - 1, startRow + 1, startColumn, memo)% MOD;
            }
            if (!isOutOfGrid(m, n, startRow, startColumn + 1)) {
                paths += solve(m, n, move - 1, startRow, startColumn + 1, memo)% MOD;
            }
            if (!isOutOfGrid(m, n, startRow - 1, startColumn)) {
                paths += solve(m, n, move - 1, startRow - 1, startColumn, memo)% MOD;
            }
            if (!isOutOfGrid(m, n, startRow, startColumn - 1)) {
                paths += solve(m, n, move - 1, startRow, startColumn - 1, memo)% MOD;
            }

            memo[startRow][startColumn][move] = paths % MOD;
            return paths % MOD;
        }
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int paths = 0;

    Matrix memo(m, vector<vector<int>>(n, vector<int>(51, -1)));
        for (int move = maxMove; move > 0; move--) {
            paths += solve(m, n, move, startRow, startColumn, memo);
            paths %= 1000000007; 
        }
        return paths % 1000000007;
    }
};