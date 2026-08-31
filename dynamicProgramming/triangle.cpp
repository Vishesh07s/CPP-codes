class Solution
{
public:
  // recursive method
  int solve(int i, int j, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
  {
    if (i == n - 1)
      return triangle[n - 1][j];
    if (dp[i][j] != -1)
      return dp[i][j];
    int down = triangle[i][j] + solve(i + 1, j, triangle, n, dp);
    int diag = triangle[i][j] + solve(i + 1, j + 1, triangle, n, dp);
    return dp[i][j] = min(down, diag);
  }
  int minimumTotal(vector<vector<int>> &triangle)
  {
    // space optimised method
    int n = triangle.size();

    // base case is when i = n-1
    vector<int> prev(n, 0);
    for (int j = 0; j < n; j++)
    {
      prev[j] = triangle[n - 1][j];
    }

    for (int i = n - 2; i >= 0; i--)
    {
      vector<int> curr(n, 0);
      for (int j = i; j >= 0; j--)
      {
        int down = triangle[i][j] + prev[j];
        int diag = triangle[i][j] + prev[j + 1];
        curr[j] = min(down, diag);
      }
      prev = curr;
    }
    return prev[0];
  }
};