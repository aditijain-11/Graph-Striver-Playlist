//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> mat, int delRow[], int delCol[])
    {
        vis[row][col] = 1;
        int N = mat.size();
        int M = mat[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow < N && nrow >= 0 && ncol < M && ncol >= 0 && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delRow, delCol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int N = mat.size();
        int M = mat[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, (vector<int>(m, 0)));
        for (int i = 0; i < M; i++)
        {
            // for first row
            if (!vis[0][i] && mat[0][i] == 'O')
            {
                dfs(0, i, vis, mat, delRow, delCol);
            }
            // for last row
            if (!vis[N - 1][i] && mat[N - 1][i] == 'O')
            {
                dfs(N - 1, i, vis, mat, delRow, delCol);
            }
        }
        for (int i = 0; i < n; i++)
        {
            // for first column
            if (!vis[i][0] && mat[i][0] == 'O')
            {
                dfs(i, 0, vis, mat, delRow, delCol);
            }
            // for last column
            if (!vis[i][M - 1] && mat[i][M - 1] == 'O')
            {
                dfs(i, M - 1, vis, mat, delRow, delCol);
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!vis[i][j] && mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends