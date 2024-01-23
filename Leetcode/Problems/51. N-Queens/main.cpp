#include <bits/stdc++.h>
using namespace std;

void solveNQueens(int col, vector<string> &board, vector<vector<string>> &sol, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal){
    if(col == board.size()){
        sol.push_back(board);
        return;
    }
    for(int row = 0; row < board.size(); row++){
        if(!leftRow[row] && !upperDiagonal[row + col] && !lowerDiagonal[board.size() - 1 + col - row]){
            leftRow[row] = true;
            upperDiagonal[row + col] = true;
            lowerDiagonal[board.size() - 1 + col - row] = true;
            board[row][col] = 'Q';
            solveNQueens(col + 1, board, sol, leftRow, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            leftRow[row] = false;
            upperDiagonal[row + col] = false;
            lowerDiagonal[board.size() - 1 + col - row] = false;
            

        }
    }

    
}
int main()
{
    int n;
    cin >> n;
    vector<vector<string>> sol;
    string empty(n, '.');
    vector<string> board(n, empty);
    vector<bool> leftRow(n, false), upperDiagonal(2 * n - 1), lowerDiagonal(2 * n - 1);
    solveNQueens(0, board, sol, leftRow, upperDiagonal, lowerDiagonal);
    for (auto board : sol)
    {
        for (auto i : board)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
            cout << endl;
    }

    return 0;
}