#include <bits/stdc++.h>
class Solution
{
public:
    void f(int index, int swaps, int n, vector<int> &input, vector<vector<int>> &sol)
    {

        for (int i = index; i < n; i++)
        {
            if (swaps == n)
            {
                sol.push_back(input);
            }
            swap(input[i], input[index]);
            f(i, i - index + 1, n, input, sol);
            swap(input[i], input[index]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> sol;
        vector<int> temp;
        vector<bool> elementsTaken(nums.size(), false);

        f(0, 0, nums.size(), nums, sol);
        return sol;
    }
};