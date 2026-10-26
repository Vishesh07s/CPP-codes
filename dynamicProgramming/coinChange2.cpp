class Solution {
public:
  typedef long long ll;
  //RECRURSION METHOD
    int f(int ind, int amt, vector<int> & coins){
        if(amt == 0) return 1;
        if(ind == 0){
            if(amt % coins[0] == 0) return 1;
            else return 0;
        }
        int notTake = f(ind - 1, amt, coins);
        int take = 0;
        if(coins[ind] <= amt){
            take = f(ind, amt - coins[ind], coins);
        }
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        //TABULATION METHOD 
        int n = coins.size();
        vector<vector<ll>> dp(n, vector<ll>(amount+1, 0));

        for(int amt = 0; amt <= amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = 1;
        }

        for(int ind = 1; ind < n; ind++){
            for(int amt = 0; amt <= amount; amt++){
                int notTake = dp[ind - 1][amt];
                int take = 0;
                if(coins[ind] <= amt) {
                    take = dp[ind][amt - coins[ind]];
                }
                dp[ind][amt] = (ll)take  + notTake;
            }

        }
        

        return dp[n-1][amount];
    }
};