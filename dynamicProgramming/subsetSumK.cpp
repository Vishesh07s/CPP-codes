#include <bits/stdc++.h>
// RECURSION METHOD
bool f(int idx, int target, int n, vector<int> &arr)
{
  if (target == 0)
    return true;
  if (idx == 0)
    return (arr[0] == target);
  bool notTake = f(idx - 1, target, n, arr);
  bool take = false;
  if (target >= arr[idx])
  {
    take = f(idx - 1, target - arr[idx], n, arr);
  }
  return take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  // TABULATION METHOD
  vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  dp[0][arr[0]] = true;
  for (int idx = 1; idx < n; idx++)
  {
    for (int target = 1; target <= k; target++)
    {
      bool notTake = dp[idx - 1][target];
      bool take = false;
      if (target >= arr[idx])
      {
        take = dp[idx - 1][target - arr[idx]];
      }
      dp[idx][target] = take || notTake;
    }
  }
  return dp[n - 1][k];
}