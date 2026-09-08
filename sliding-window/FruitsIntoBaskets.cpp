class Solution
{
public:
  int totalFruit(vector<int> &f)
  {
    int n = f.size();
    int k = 2;
    unordered_map<int, int> mpp;
    int l = 0, r = 0, maxlen = 0;
    while (r < n)
    {
      mpp[f[r]]++;
      if (mpp.size() > k)
      {
        while (mpp.size() > k)
        {
          mpp[f[l]]--;
          if (mpp[f[l]] == 0)
            mpp.erase(f[l]);
          l++;
        }
      }
      if (mpp.size() <= k)
      {
        maxlen = max(maxlen, r - l + 1);
      }
      r++;
    }
    return maxlen;
  }
};