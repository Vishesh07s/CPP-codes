class Solution
{
public:
  string minRemoveToMakeValid(string s)
  {
    int n = s.size();
    stack<int> st;
    string ans = "";
    int balance = 0;
    vector<bool> remove(n, false);
    for (int i = 0; i < n; i++)
    {
      if (s[i] == '(')
      {
        balance++;
        st.push(i);
      }
      else if (s[i] == ')')
      {
        balance--;
        if (balance >= 0)
        {
          st.pop();
        }
        else
        {
          remove[i] = true;
          balance = 0;
        }
      }
      else
        continue;
    }

    while (!st.empty())
    { // handles extra opening parenthesis like in example 3
      remove[st.top()] = true;
      st.pop();
    }

    for (int i = 0; i < n; i++)
    {
      if (remove[i] == false)
        ans.push_back(s[i]); // if remove == false mtlb element needs no to be removed so we add it to our ans
    }
    return ans;
  }
};