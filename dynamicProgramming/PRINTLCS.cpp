// NOTE :  USED LENGTH OF LCS code
// string findLCS(int n, int m, string &s1, string &s2)
// {
//   vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//   // BASE CASE
//   for (int i = 0; i <= n; i++)
//   {
//     dp[i][0] = 0;
//   }
//   for (int j = 0; j <= m; j++)
//   {
//     dp[0][j] = 0;
//   }
//   // MAIN LOGIC
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 1; j <= m; j++)
//     {
//       if (s1[i - 1] == s2[j - 1])
//         dp[i][j] = 1 + dp[i - 1][j - 1];
//       else
//       {
//         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//       }
//     }
//   }

//   int len = dp[n][m];
//   string ans = "";
//   for (int i = 0; i < len; i++)
//   {
//     ans += '$';
//   }
//   // BACKTRACKING DP TABLE TO GET RESULTANT STRING
//   int ind1 = n;
//   int ind2 = m;
//   int ansInd = len - 1;

//   while (ind1 > 0 && ind2 > 0)
//   {
//     if (s1[ind1 - 1] == s2[ind2 - 1])
//     {
//       ans[ansInd] = s1[ind1 - 1];
//       ansInd--;
//       ind1--;
//       ind2--;
//     }
//     else if (s1[ind1 - 1] != s2[ind2 - 1] && dp[ind1 - 1][ind2] > dp[ind1][ind2 - 1])
//       ind1--;
//     else
//       ind2--;
//   }
//   return ans;
// }