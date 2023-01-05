//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,
             int ini, int newc, int delRow[], int delCol[])
    {
        ans[row][col] = newc;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && ans[nrow][ncol] != newc && image[nrow][ncol] == ini)
            {
                dfs(nrow, ncol, ans, image, ini, newc, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        vector<vector<int>> ans = image;
        int delRow[] = {0, -1, 0, 1};
        int delCol[] = {-1, 0, 1, 0};
        int initialColor = image[sr][sc];
        dfs(sr, sc, ans, image, initialColor, newColor, delRow, delCol);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends