#include <bits/stdc++.h>
class Solution
{
public:
  int largestRectangleArea(vector<int> &arr)
  {
    int n = arr.size();
    stack<int> st;
    int area = 0;
    for (int i = 0; i < n; i++)
    {
      while (!st.empty() && arr[st.top()] > arr[i])
      {
        int element = arr[st.top()];
        int nse = i;
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        area = max(area, element * (nse - pse - 1));
      }
      st.push(i);
    }
    while (!st.empty())
    {
      int nse = n;
      int element = arr[st.top()];
      st.pop();
      int pse = st.empty() ? -1 : st.top();
      area = max(area, element * (nse - pse - 1));
    }
    return area;
  }
};
