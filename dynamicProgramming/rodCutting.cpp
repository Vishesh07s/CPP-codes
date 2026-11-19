int solve(int ind, int n, vector<int> &price)
{
  // RECURSIVE METHOD
  if (ind == 0)
  {
    return n * price[0];
  }
  int notTake = solve(ind - 1, n, price);
  int take = INT_MIN;
  int rodlen = ind + 1;
  if (rodlen <= n)
  {
    take = price[ind] + solve(ind, n - rodlen, price);
  }
  return max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
  // TABULATION  METHOD
  int N = price.size();
  vector<vector<int>> dp(N, vector<int>(n + 1, 0));
  // Base case
  for (int i = 0; i <= n; i++)
  {
    dp[0][i] = i * price[0];
  }
  for (int ind = 1; ind < N; ind++)
  {
    for (int r = 0; r <= n; r++)
    {
      int notTake = dp[ind - 1][r];
      int take = INT_MIN;
      int rodlen = ind + 1;
      if (rodlen <= r)
      {
        take = price[ind] + dp[ind][r - rodlen];
      }
      dp[ind][r] = max(take, notTake);
    }
  }
  return dp[N - 1][n];
}
