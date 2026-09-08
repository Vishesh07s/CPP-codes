// MEMOIZATION
class Solution
{
public:
  int n;
  int m;
  int solve(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
  {
    if (j < 0 || j >= m)
      return 1e9;
    if (i == 0)
      return a[0][j];
    if (dp[i][j] != -1)
      return dp[i][j];
    int up = a[i][j] + solve(i - 1, j, a, dp);
    int ul = a[i][j] + solve(i - 1, j - 1, a, dp);
    int ur = a[i][j] + solve(i - 1, j + 1, a, dp);
    return dp[i][j] = min({up, ul, ur});
  }
  int minFallingPathSum(vector<vector<int>> &matrix)
  {
    n = matrix.size();
    m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int mini = 1e9;
    for (int j = 0; j < m; j++)
    {
      mini = min(mini, solve(n - 1, j, matrix, dp));
    }
    return mini;
  }
};

///////////   TABULATION ///////

int minFallingPathSum(vector<vector<int>> &a)
{
  n = a.size();
  m = a.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));

  // base case
  for (int j = 0; j < m; j++)
  {
    dp[0][j] = a[0][j];
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      int up = a[i][j];
      if (i > 0)
        up += dp[i - 1][j];
      else
        up += 1e8;
      int ul = a[i][j];
      if (j > 0)
        ul += dp[i - 1][j - 1];
      else
        ul += 1e8;
      int ur = a[i][j];
      if (j < m - 1)
        ur += dp[i - 1][j + 1];
      else
        ur += 1e8;
      dp[i][j] = min({up, ul, ur});
    }
  }
  int mini = dp[n - 1][0];
  for (int j = 1; j < m; j++)
  {
    mini = min(mini, dp[n - 1][j]);
  }
  return mini;
}
