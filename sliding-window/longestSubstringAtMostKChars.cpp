// longest substring with at most k characters
#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
  int n = str.size();
  unordered_map<char, int> mpp;
  int l = 0, r = 0, maxlen = 0;
  while (r < n)
  {
    mpp[str[r]]++;
    if (mpp.size() > k)
    {
      while (mpp.size() > k)
      {
        mpp[str[l]]--;
        if (mpp[str[l]] == 0)
          mpp.erase(str[l]);
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
