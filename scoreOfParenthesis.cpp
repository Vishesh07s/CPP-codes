class Solution
{
public:
  int scoreOfParentheses(string s)
  {
    stack<int> st; // agar open bracket aaega toh 0 push karenge aur agar closed aaega toh 0 pop karke 1 push karenge
    for (auto &c : s)
    {
      int val = 0;
      if (c == '(')
        st.push(0);
      else
      {
        while (!st.empty() && st.top() != 0)
        {
          val += st.top();
          st.pop();
        }
        val = max(2 * val, 1); // handles () = 1 score
        st.pop();              // remove marker 0
        st.push(val);
      }
    }
    int ans = 0;
    while (!st.empty())
    {
      ans += st.top();
      st.pop();
    }
    return ans;
  }
};