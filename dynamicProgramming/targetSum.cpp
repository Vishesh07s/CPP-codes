class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // P -> abs(sum of all positive numbers)
        //  N -> abs(sum of all negative numbers)
        // equation1 : P - N = target
        //equation 2: P + N = totalSum 
        //adding equation 1 and 2 :  P = (target + totalSum)/2
        //Our question boils down to "How many subsets have sum P?"
        int n =  nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(),0);
        if(totalSum <  abs(target)) return 0;
        if((target + totalSum) % 2 != 0) return 0; //P must be an integer
        int P = (target + totalSum)/2;
        vector<vector<int>> dp(n, vector<int>(P+1,0));
        dp[0][0] = 1;
        if(nums[0] <= P) dp[0][nums[0]]++;
        for(int idx = 1; idx < n; idx++){
            for(int sum = 0; sum <= P; sum++){
                int notPick = dp[idx-1][sum];
                int Pick = 0;
                if(sum >= nums[idx]) Pick = dp[idx-1][sum - nums[idx]];
                dp[idx][sum] = Pick +  notPick;
            }
        }
        return dp[n-1][P];

    }
};