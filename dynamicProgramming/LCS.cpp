//    MEMOIZATION
// class Solution {
// public:
//     int lcs(int ind1, int ind2, string s1, string s2,vector<vector<int>> &dp){
//         if(ind1 < 0 || ind2 < 0) return 0;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(s1[ind1] == s2[ind2]) return 1 + lcs(ind1-1,ind2-1,s1,s2,dp);
//         return dp[ind1][ind2] =  max(lcs(ind1-1,ind2,s1,s2,dp), lcs(ind1,ind2-1,s1,s2,dp));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int n1 = text1.size();
//         int n2 = text2.size();
//         vector<vector<int>> dp(n1,vector<int>(n2,-1));
//         return lcs( n1-1, n2-1, text1, text2,dp);
//     }
// };

// TABULATION

// int longestCommonSubsequence(string s1, string s2)
// {
//   int n1 = s1.size();
//   int n2 = s2.size();
//   vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
//   // right shifting indices to store in dp bcoz base case includes  negative index
//   // BASE CASE becomes -> if(ind1 == 0 || ind2 == 0) return 0;
//   for (int i = 0; i <= n1; i++)
//   {
//     dp[i][0] = 0;
//   }
//   for (int j = 0; j <= n2; j++)
//   {
//     dp[0][j] = 0;
//   }

//   for (int i = 1; i <= n1; i++)
//   {
//     for (int j = 1; j <= n2; j++)
//     {
//       if (s1[i - 1] == s2[j - 1])
//         dp[i][j] = 1 + dp[i - 1][j - 1];
//       else
//         dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//     }
//   }
//   return dp[n1][n2];
// }
// }
// ;